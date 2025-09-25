# RtlSubtreePredecessor function

## Description

The **RtlSubtreePredecessor** routine returns a pointer to the predecessor of the specified node within the subtree that is rooted at that node.

## Parameters

### `Links` [in]

A pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Return value

**RtlSubtreePredecessor** returns a pointer to the subtree predecessor of the node at *Links*, or **NULL** if the node has no subtree predecessor.

## Remarks

If the node at *Links* has a left subtree, the rightmost node of that subtree is the subtree predecessor.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlSubtreePredecessor** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlRealPredecessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrealpredecessor)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)

[RtlSubtreeSuccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsubtreesuccessor)