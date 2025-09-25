# RtlRightChild macro

## Description

The **RtlRightChild** routine returns a pointer to the right child of the specified splay link node.

## Parameters

### `Links` [in]

Pointer to the node whose right child is to be returned. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

**RtlRightChild** returns a pointer to the right child of the node at Links, or it returns NULL if the specified node has no right child.

**RtlRightChild** can be called repeatedly in conjunction with **RtlParent** and **RtlLeftChild** to walk a splay link tree.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlRightChild** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlleftchild)

[RtlParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlparent)