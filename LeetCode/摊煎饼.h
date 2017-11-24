#pragma once
/****************************************************************/
//
// �ӱ�����ʵ��
//
/****************************************************************/
#include <cstdio>
#include<cassert>
class CPrefixSorting
{
public:

	CPrefixSorting()
	{
		m_nCakeCnt = 0;
		m_nMaxSwap = 0;
		m_CakeArray = NULL;
		m_SwapArray = NULL;
		m_ReverseCakeArray = NULL;
		m_ReverseCakeArraySwap = NULL;
	}

	~CPrefixSorting()
	{
		printf("1");
		if (m_CakeArray != NULL)
		{
			delete[]m_CakeArray;
		}
		if (m_SwapArray != NULL)
		{
			delete[]m_SwapArray;
		}
		if (m_ReverseCakeArray != NULL)
		{
			delete[]m_ReverseCakeArray;
		}
		if (m_ReverseCakeArraySwap != NULL)
		{
			delete[]m_ReverseCakeArraySwap;
		}
		printf("2");
	}

	//
	// �����ӱ���ת��Ϣ
	// @param
	// pCakeArray    �洢�ӱ���������
	// nCakeCnt    �ӱ�����
	//
	void Run(int* pCakeArray, int nCakeCnt)
	{
		Init(pCakeArray, nCakeCnt);

		m_nSearch = 0;
		Search(0);
	}

	//
	// ����ӱ����巭ת�Ĵ���
	//
	void Output()
	{
		for (int i = 0; i < m_nMaxSwap; i++)
		{
			printf("%d ", m_SwapArray[i]);
		}

		printf("\n |Search Times| : %d\n", m_nSearch);
		printf("Total Swap times = %d\n", m_nMaxSwap);
	}

private:

	//
	// ��ʼ��������Ϣ
	// @param
	// pCakeArray    �洢�ӱ���������
	// nCakeCnt    �ӱ�����
	//
	void Init(int* pCakeArray, int nCakeCnt)
	{
		assert(pCakeArray != NULL);
		assert(nCakeCnt > 0);

		m_nCakeCnt = nCakeCnt;

		// ��ʼ���ӱ�����
		m_CakeArray = new int[m_nCakeCnt];
		assert(m_CakeArray != NULL);
		for (int i = 0; i < m_nCakeCnt; i++)
		{
			m_CakeArray[i] = pCakeArray[i];
		}

		// ������ཻ��������Ϣ
		m_nMaxSwap = UpBound(m_nCakeCnt);

		// ��ʼ������������� 
		m_SwapArray = new int[m_nMaxSwap + 1];
		assert(m_SwapArray != NULL);

		// ��ʼ���м佻�������Ϣ
		m_ReverseCakeArray = new int[m_nCakeCnt];
		for (int i = 0; i < m_nCakeCnt; i++)
		{
			m_ReverseCakeArray[i] = m_CakeArray[i];
		}
		m_ReverseCakeArraySwap = new int[m_nMaxSwap + 1];
	}


	//
	// Ѱ�ҵ�ǰ��ת���Ͻ�
	//
	//
	int UpBound(int nCakeCnt)
	{
		return nCakeCnt * 2;
	}

	//
	// Ѱ�ҵ�ǰ��ת���½�
	//
	//
	int LowerBound(int* pCakeArray, int nCakeCnt)
	{
		int t, ret = 0;

		// ���ݵ�ǰ�����������Ϣ������ж�������Ҫ�������ٴ�
		for (int i = 1; i < nCakeCnt; i++)
		{
			// �ж�λ�����ڵ������ӱ����Ƿ�Ϊ�ߴ����������ڵ�
			t = pCakeArray[i] - pCakeArray[i - 1];
			if ((t == 1) || (t == -1))
			{
			}
			else
			{
				ret++;
			}
		}
		return ret;
	}

	// �����������
	void Search(int step)
	{
		int i, nEstimate;

		m_nSearch++;

		// ���������������Ҫ����С��������
		nEstimate = LowerBound(m_ReverseCakeArray, m_nCakeCnt);
		if (step + nEstimate > m_nMaxSwap)
			return;

		// ����Ѿ��ź��򣬼���ת��ɣ�������
		if (IsSorted(m_ReverseCakeArray, m_nCakeCnt))
		{
			if (step < m_nMaxSwap)
			{
				m_nMaxSwap = step;
				for (i = 0; i < m_nMaxSwap; i++)
					m_SwapArray[i] = m_ReverseCakeArraySwap[i];
			}
			return;
		}

		// �ݹ���з�ת
		for (i = 1; i < m_nCakeCnt; i++)
		{
			Revert(0, i);
			m_ReverseCakeArraySwap[step] = i;
			Search(step + 1);
			Revert(0, i);
		}
	}
	//
	// true : �Ѿ��ź���
	// false : δ����
	//
	bool IsSorted(int* pCakeArray, int nCakeCnt)
	{
		for (int i = 1; i < nCakeCnt; i++)
		{
			if (pCakeArray[i - 1] > pCakeArray[i])
			{
				return false;
			}
		}
		return true;
	}

	//
	// ��ת�ӱ���Ϣ
	//    
	void Revert(int nBegin, int nEnd)
	{
		assert(nEnd > nBegin);
		int i, j, t;

		// ��ת�ӱ���Ϣ
		for (i = nBegin, j = nEnd; i < j; i++, j--)
		{
			t = m_ReverseCakeArray[i];
			m_ReverseCakeArray[i] = m_ReverseCakeArray[j];
			m_ReverseCakeArray[j] = t;
		}
	}

private:

	int* m_CakeArray;    // �ӱ���Ϣ����
	int m_nCakeCnt;    // �ӱ�����
	int m_nMaxSwap;    // ��ཻ������������ǰ����ƶϣ��������Ϊ
					   // m_nCakeCnt * 2 
	int* m_SwapArray;    // �����������

	int* m_ReverseCakeArray;    // ��ǰ��ת�ӱ���Ϣ����
	int* m_ReverseCakeArraySwap;    // ��ǰ��ת�ӱ������������
	int m_nSearch;    // ��ǰ����������Ϣ
};


int main()
{
	CPrefixSorting a;
	int cakeArry[] = { 3,2,1,6,5,4,9,8,7,0 };
	a.Run(cakeArry, sizeof(cakeArry) / sizeof(int));
	a.Output();
	printf("\n");
	CPrefixSorting b;
	int cakeArry1[] = { 12,3,2,1,11,6,5,10,4,9,8,7,0 };
	b.Run(cakeArry1, sizeof(cakeArry1) / sizeof(int));
	b.Output();
	printf("\n");
	CPrefixSorting c;
	int cakeArry2[] = { 2,0,1 };
	c.Run(cakeArry2, sizeof(cakeArry2) / sizeof(int));
	c.Output();
	return 0;
}

