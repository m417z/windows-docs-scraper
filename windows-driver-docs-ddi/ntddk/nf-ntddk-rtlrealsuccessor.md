# RtlRealSuccessor function

## Description

The **RtlRealSuccessor** routine returns a pointer to the successor of the specified node in the splay link tree.

## Parameters

### `Links` [in]

Pointer to the node. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Return value

**RtlRealSuccessor** returns a pointer to the successor of the node at *Links*, or **NULL** if the node has no successor.

## Remarks

The real successor of a given node is determined as follows:

* If the given node has a right subtree, the leftmost node in the right subtree of the node at *Links* is the successor. Note that **RtlSubtreeSuccessor** returns the same result for this case.
* Otherwise, the nearest ancestor node, of which the given node is a left-subtree descendant, is the successor.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlRealSuccessor** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlRealPredecessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrealpredecessor)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)

[RtlSubtreeSuccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsubtreesuccessor)