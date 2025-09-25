# RtlInitializeSplayLinks function

## Description

The **RtlInitializeSplayLinks** routine initializes a splay link node.

## Parameters

### `Links` [in]

Pointer to a caller-allocated buffer, which must be at least **sizeof(**RTL_SPLAY_LINK**)**, to contain the initialized splay link node.

## Remarks

Every splay link node, including the initial root node of the splay link tree, must be initialized by calling **RtlInitializeSplayLinks** before it is passed to any other **Rtl** splay link routine. The initialized splay link node structure should be considered opaque.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlInitializeSplayLinks** must be running at IRQL <= DISPATCH_LEVEL if the memory at *Links* is nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[ExInitializeFastMutex](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializefastmutex)

[RtlDeleteNoSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtldeletenosplay)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlIsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisleftchild)

[RtlIsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisrightchild)

[RtlIsRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisroot)

[RtlLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlleftchild)

[RtlParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlparent)

[RtlRealPredecessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrealpredecessor)

[RtlRealSuccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrealsuccessor)

[RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)

[RtlSubtreePredecessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsubtreepredecessor)

[RtlSubtreeSuccessor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsubtreesuccessor)