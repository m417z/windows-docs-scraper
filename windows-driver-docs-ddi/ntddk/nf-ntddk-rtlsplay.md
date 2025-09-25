# RtlSplay function

## Description

The **RtlSplay** routine rebalances, or "splays," a splay link tree around the specified splay link, making that link the new root of the tree.

## Parameters

### `Links` [in, out]

A pointer to the node that is to become the root node of the rebalanced splay link tree. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Return value

**RtlSplay** returns the *Links* pointer when it has rebalanced the tree.

## Remarks

If L is the given link, P is its parent node, and G is its grandparent node, **RtlSplay** rebalances a splay link tree according to one of the six patterns shown in the following figure.

![Diagram illustrating the rebalancing of a splay link tree, where L is the given link, P is its parent node, and G is its grandparent node.](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/images/treertlsplay.png)

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlSplay** must be running at IRQL <= DISPATCH_LEVEL if the tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldelete)

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)