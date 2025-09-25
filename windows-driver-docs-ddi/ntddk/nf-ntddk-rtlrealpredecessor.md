# RtlRealPredecessor function

## Description

The **RtlRealPredecessor** routine returns a pointer to the predecessor of the specified node in the splay link tree.

## Parameters

### `Links` [in]

Pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Return value

**RtlRealPredecessor** returns a pointer to the predecessor of the node at *Links*, or **NULL** if the node has no predecessor.

## Remarks

The predecessor of a given node is determined as follows:

* If the given node has a left subtree, the rightmost node in the left subtree of the node at *Links* is the predecessor. Note that **RtlSubtreePredecessor** returns the same result for this case.
* Otherwise, the nearest ancestor node, of which the given node is a right-subtree descendant, is the predecessor.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlRealPredecessor** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlRealSuccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrealsuccessor)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)

[RtlSubtreePredecessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsubtreepredecessor)