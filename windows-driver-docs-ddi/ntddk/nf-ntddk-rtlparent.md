# RtlParent macro

## Description

The **RtlParent** routine returns a pointer to the parent of the specified node in a splay link tree.

## Parameters

### `Links` [in]

Pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

**RtlParent** returns a pointer to the parent of the node at Links, or it returns the Links pointer if the given node is the root node of the tree.

**RtlParent** can be called repeatedly in conjunction with **RtlLeftChild** and **RtlRightChild** to walk a splay link tree.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlParent** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlIsRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisroot)

[RtlLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlleftchild)

[RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild)