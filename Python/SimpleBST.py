class Node:
  def __init__(self,val):
    self.right = None
    self.left = None
    self.val = val

def insertNode(root,val):
  if root is None:
    return Node(val)
  else:
    if root.val == val:
      return root
    elif root.val < val:
      root.left = insertNode(root.left,val)
    else:
      root.right = insertNode(root.right,val)
  return root

def PrintinOrder(root):
  if root:
    PrintinOrder(root.left)
    print(root.val)
    PrintinOrder(root.right)
    
root = Node(100)
root = insertNode(root,20)
root = insertNode(root,10)
root = insertNode(root,150)
root = insertNode(root,40)
root = insertNode(root,50)
root = insertNode(root,90)
root = insertNode(root,110)
root = insertNode(root,60)

PrintinOrder(root)
