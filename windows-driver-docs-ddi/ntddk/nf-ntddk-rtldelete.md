# RtlDelete function

## Description

The **RtlDelete** routine deletes the specified node from the splay link tree.

## Parameters

### `Links` [in]

Pointer to the node to be deleted. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Return value

**RtlDelete** returns a pointer to the root of the splay link tree from which the given node was deleted, or it returns **NULL** if the tree is empty.

## Remarks

**RtlDelete** rebalances the splay link tree after the node is deleted. To delete a node without rebalancing the tree, use **RtlDeleteNoSplay** instead of **RtlDelete**.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlDelete** must be running at IRQL <= DISPATCH_LEVEL if the splay link tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlDeleteNoSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeletenosplay)

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)