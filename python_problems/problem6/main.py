
class BinaryTree:

    class Node:
        def __init__(self, key, value):
            self.key = key
            self.value = value
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def insert(self, key, value):
        new_node = self.Node(key, value)

        if self.root is None:
            self.root = new_node
        
        trav = self.root
        while True:
            if trav.key > new_node.key: # go to left subtree
                if not trav.left:
                    trav.left = new_node
                    return
                else:
                    trav = trav.left
            elif trav.key < new_node.key: # go to right subtree
                if not trav.right:
                    trav.right = new_node
                    return
                else:
                    trav = trav.right
            else:
                trav.values = trav.value + new_node.value
                return

    def print(self):
        """Prints tree, in order traversal"""
        self.inorder_traversal_print(self.root)

    def inorder_traversal_print(self, root):
        if root is None:
            return 
        else:
            self.inorder_traversal_print(root.left)
            print(root.key)
            self.inorder_traversal_print(root.right)


def test_binary_tree():
    btree = BinaryTree()
    btree.insert(20, 2)
    btree.insert(13, 3)
    btree.insert(45, 1)
    btree.insert(50, 5)
    btree.insert(5, 2)
    btree.insert(15, 7)
    btree.print()















