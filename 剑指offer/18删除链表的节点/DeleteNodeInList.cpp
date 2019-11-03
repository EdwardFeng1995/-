// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣

// ˼·����ͳ��ɾ������ڵ㣬temp->next->val = node->val; temp->next = temp->next->next;
// ��ͳ������Ҫֱ��Ҫɾ���ڵ��ǰһ���ڵ㣬��Ҫ������ʱ�临�Ӷ�O(n)
// ����Ҫ��ʱ�临�Ӷ�O��1���������ɾ���ڵ㲻��β�ڵ㣬����Ҫɾ���ڵ����һ�ڵ㸲��Ҫɾ���Ľڵ�
// node->val = node->next->val;
// node->next = node->next->next;
// ���Ҫɾ������β�ڵ㣬������Ҫ�����õ�β�ڵ��ǰһ���ڵ�
// �ܵ�ƽ��ʱ�临�Ӷ�Ϊ[(n-1)O(n)+O(n)]/n
//
// ����������leetcode237�����ǵ������Ķ���⣬��������
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    // Ҫɾ���Ľ�㲻��β���
    if(pToBeDeleted->m_pNext != nullptr)
    {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;
 
        delete pNext;
        pNext = nullptr;
    }
    // ����ֻ��һ����㣬ɾ��ͷ��㣨Ҳ��β��㣩
    else if(*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // �������ж����㣬ɾ��β���
    else
    {
        ListNode* pNode = *pListHead;
        while(pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;            
        }
 
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

