// ���� Ž�� Ʈ�� ����
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

// Ž�� �Լ�(����� Ž��)
TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)	// ���� Ž�� Ʈ������ ���� �ڽ��� key�� ���� ���� ����� �̷����
		return search(node->left, key);
	else                        // ���� Ž�� Ʈ������ ������ �ڽ��� key�� ���� ū ����� �̷����
		return search(node->right, key);
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ
	if (node == NULL) return new_node(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ������
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ
	return node;
}
// �ּ� �� ã��
TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}

// ���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
// ���ο� ��Ʈ ��带 ��ȯ
TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� ����
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	// Ű�� ��Ʈ�� ������ �� ��带 ����
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// �� ��° ���
		TreeNode* temp = min_value_node(root->right);

		// ���� ��ȸ�� �İ� ��带 ����
		root->key = temp->key;
		// ���� ��ȸ�� �İ� ��带 ����
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}
// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);		// ���� ����Ʈ�� ��ȸ
		printf("|%d| ", root->key);	// ��� �湮
		inorder(root->right);		// ������ ����Ʈ�� ��ȸ
	}
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* temp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰��� \n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰����� ���� \n");
	return 0;
}