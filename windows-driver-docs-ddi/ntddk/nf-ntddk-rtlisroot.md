# RtlIsRoot macro

## Description

The **RtlIsRoot** routine determines whether the specified node is the root node of a splay link tree.

## Parameters

### `Links` [in]

Pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

**RtlIsRoot** returns TRUE if the node at Links has no parent node, FALSE otherwise.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlIsRoot** must be running at IRQL <= DISPATCH_LEVEL if the splay link tree or just-initialized node at *Links* is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlIsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisleftchild)

[RtlIsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisrightchild)