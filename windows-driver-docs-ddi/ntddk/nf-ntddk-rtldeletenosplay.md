# RtlDeleteNoSplay function

## Description

The **RtlDeleteNoSplay** routine deletes the specified node from the splay link tree.

## Parameters

### `Links` [in]

A pointer to the node to be deleted. The node must have been initialized by calling **RtlInitializeSplayLinks**.

### `Root` [in, out]

A pointer to the caller's pointer to the root node of the splay link tree. The caller's pointer is updated after the node is deleted.

## Return value

None

## Remarks

Unlike **RtlDelete**, **RtlDeleteNoSplay** does not rebalance the splay link tree after the node is deleted.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlDeleteNoSplay** must be running at IRQL <= DISPATCH_LEVEL if the splay link tree is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldelete)

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)