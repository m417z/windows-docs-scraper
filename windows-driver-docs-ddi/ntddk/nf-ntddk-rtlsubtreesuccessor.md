# RtlSubtreeSuccessor function

## Description

The **RtlSubtreeSuccessor** routine returns a pointer to the successor of the specified node within the subtree that is rooted at that node.

## Parameters

### `Links` [in]

A pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Return value

**RtlSubtreeSuccessor** returns a pointer to the subtree successor of the node at *Links*, or **NULL** if the given node has no subtree successor.

## Remarks

If the node at *Links* has a right subtree, the leftmost node of that subtree is the subtree successor.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlSubtreeSuccessor** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. If the tree is paged, callers must be running at IRQL < DISPATCH_LEVEL. Usually callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlRealSuccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrealsuccessor)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)

[RtlSubtreePredecessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsubtreepredecessor)