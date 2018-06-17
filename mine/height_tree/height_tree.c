struct s_node {
		int           value;
		struct s_node **nodes;
};

int		get_height(struct s_node *root, int max)
{
	int curr = -1;

	if (!root)
		return (max);
	while (root->nodes)
	{
		curr = get_height(root->nodes, max);
		curr++;
		if (max < curr)
			max = curr;
		root->nodes++;
	}
	return (max);
}

int		height_tree(struct s_node *root)
{
	int max = -1;
	
	max = get_height(root, max);
	return (max);
}
