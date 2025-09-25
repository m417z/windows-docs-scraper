# RtlIsRightChild macro

## Description

The **RtlIsRightChild** routine determines whether a given splay link is the right child of a node in a splay link tree.

## Parameters

### `Links` [in]

Pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

**RtlIsRightChild** returns TRUE if the given node at Links is the right child of its parent node, FALSE otherwise.

The given node at *Links* must have a parent node in the tree. A caller can determine whether this node has a parent with **RtlIsRoot**. If **RtlIsRoot** returns **FALSE**, *Links* is a valid parameter to **RtlIsRightChild**.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlIsRightChild** can be running at IRQL <= DISPATCH_LEVEL if the splay link tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlIsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisleftchild)

[RtlIsRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisroot)

[RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)