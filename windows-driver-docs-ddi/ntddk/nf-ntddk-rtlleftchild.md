# RtlLeftChild macro

## Description

The **RtlLeftChild** routine returns a pointer to the left child of the specified splay link node.

## Parameters

### `Links` [in]

Pointer to the node whose left child is to be returned. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

**RtlLeftChild** returns a pointer to the left child of the node at Links, or it returns NULL if the specified node has no left child.

**RtlLeftChild** can be called repeatedly in conjunction with **RtlParent** and **RtlRightChild** to walk a splay link tree.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlLeftChild** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlparent)

[RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild)