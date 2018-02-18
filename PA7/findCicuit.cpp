#include "findCicuit.h"
#include <unordered_set>





findCicuit::findCicuit()
{
	Node *n1 = new Node(0);
	Node *n2 = new Node(n1);
	Node *n3 = new Node(n2);
	Node *n4 = new Node(n3);
	Node *head = new Node(n4);
	


	std::unordered_set<Node *> usedLinks;
	Node *movingNode = head;

	while(movingNode != 0 )
	{
		if (usedLinks.count(movingNode))
		{
			break;
		}
		usedLinks.insert(movingNode);
		movingNode = movingNode->next;
	}
}


