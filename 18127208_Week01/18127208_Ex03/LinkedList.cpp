#include "LinkedList.h"

NODE* CreateNode(int data) {
    NODE* temp { new NODE };
    if (temp != nullptr) {
        temp->key = data;
    }
    return temp;
}

List* CreateList(NODE* p_node) {
    List* temp { new List };
    temp->p_head = temp->p_tail = p_node;
    return temp;
}

bool AddHead(List* L, int data) {
    if (L != nullptr) {
        NODE* temp { CreateNode(data) };
        temp->p_next = L->p_head;
        L->p_head = temp;
        return true;
    }
    return false;
}

bool AddTail(List* L, int data) {
    if (L != nullptr) {
        NODE* temp = { CreateNode(data) };
        if (L->p_tail != nullptr) {
            L->p_tail->p_next = temp;
        }
        L->p_tail = temp;
        return true;
    }
    return false;
}

void RemoveHead(List* L) {
    if (L != nullptr) {
        if (L->p_head != nullptr) {
            NODE* temp { L->p_head };
            L->p_head = temp->p_next;
            delete temp;
        }
    }
}

void RemoveTail(List* L) {
    if (L != nullptr) {
        NODE* cur { L->p_head };
        if (cur != nullptr) {
            while (cur->p_next != L->p_tail) {
                cur = cur->p_next;
            }
        }
        delete L->p_tail;
        L->p_tail = cur;
    } 
}

void RemoveAll(List*& L) {
    if (L != nullptr) {
        NODE* cur { L->p_head };
        NODE* temp;
        while (cur != nullptr) {
            temp = cur;
            cur = cur->p_next;
            delete temp;
        }
    }
}

void PrintList(List* L) {
    if (L != nullptr) {
        NODE* cur { L->p_head };
        while (cur != nullptr) {
            std::cout << cur->key << "\n";
            cur = cur->p_next;
        }
    }
}

int CountElements(List* L) {
    if (L != nullptr) {
        NODE* cur { L->p_head };
        int i { 0 };
        while (cur != nullptr) {
            ++i;
            cur = cur->p_next;
        }
        return i;
    }
    return -1;
}

List* ReverseList(List* L) {
    if (L != nullptr) {
        List* res { new List };
        NODE* cur { L->p_head };
        int i { 0 };
        while (cur != nullptr) {
            AddHead(res, cur->key);
            cur = cur->p_next;
        }
        return res;
    }
    return nullptr;
}

bool RemoveElementByPre(List*& L, NODE*& pre) {
    if (L != nullptr) {
        NODE* temp = pre->p_next;
        pre->p_next = temp->p_next;
        delete temp;
        return true;
    }
    return false;
}

void RemoveDuplicate(List*& L) {
    if (L != nullptr) {
        NODE* cur { L->p_head };
        if (cur != nullptr) {
            for (; cur->p_next != nullptr; cur = cur->p_next) {
                for (NODE* track = cur; track->p_next != nullptr;) {
                    if (track->p_next->key == cur->key) {
                        RemoveElementByPre(L, track);
                    }
                    else {
                        track = track->p_next;
                    }
                }
            }
        }
    }
}

bool RemoveElement(List*& L, int key) {
    if (L != nullptr) {
        NODE* head { L->p_head };
        if (head != nullptr) {
            if (head->key == key) {
                RemoveHead(L);
            }
            for (NODE* track = head; track->p_next != nullptr;) {
                if (track->p_next->key == key) {
                    RemoveElementByPre(L, track);
                }
                else {
                    track = track->p_next;
                }
            }
        }
        return true;
    }
    return false;
}

NODE* CreateNode(int data)
{
	return nullptr;
}
