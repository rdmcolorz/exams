#include <stdlib.h>
struct s_node {
		void *content;
		struct s_node *next;
};

struct s_queue {
		struct s_node *first;
		struct s_node *last;
};

struct s_queue *init(void)
{
	struct s_queue *new;
	
	new = malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

struct s_node *newNode(void *content)
{
	struct s_node *new;
	
	new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, void *content)
{
	if (queue)
	{
		if (queue->last)
		{
			queue->last->next = newNode(content);
			queue->last = queue->last->next;
		}
		else
		{
			queue->last = newNode(content);
			queue->first = queue->last;
		}
	}
}

void *dequeue(struct s_queue *queue)
{
	void *temp;

	if (queue)
	{
		if (queue->first && queue->last)
		{
			temp = queue->first->content;
			queue->first = queue->first->next;
			return (temp);
		}
		return (NULL);
	}
	return (NULL);
}

void *peek(struct s_queue *queue)
{
	if (queue)
	{
		if (queue->first && queue->last)
			return (queue->first->content);
		return (NULL);
	}
	return (NULL);
}

int isEmpty(struct s_queue *queue)
{
	if (queue)
	{
		if (queue->first && queue->last)
			return (0);
		return (1);
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	char *a = "hello";
	char *b = "my";
	char *c = "name";
	char *d = "is";
	char *e = "Taylor";
	void *peeked;
	void *poped;

	struct s_queue *new;
	new = init();
	enqueue(new, a);
	enqueue(new, b);
	enqueue(new, c);
	enqueue(new, d);
	enqueue(new, e);
	poped = dequeue(new);
	poped = dequeue(new);
	poped = dequeue(new);
	poped = dequeue(new);
	poped = dequeue(new);
	printf("this is poped: %s\n", poped);
	peeked = peek(new);
	printf("this is peek: %s\n", peeked);
	while (new->first)
	{
		printf("%s\n", new->first->content);
		new->first = new->first->next;
	}
}*/
