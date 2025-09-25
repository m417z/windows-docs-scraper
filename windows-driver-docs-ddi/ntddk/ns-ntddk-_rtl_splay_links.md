# _RTL_SPLAY_LINKS structure

## Description

The RTL_SPLAY_LINKS structure is an opaque structure and is used by the system to represent a splay link tree node.

## Members

### `Parent`

An opaque pointer to the parent node for this node. If only one node in the splay link tree exists, the value of this member is **NULL**.

### `LeftChild`

An opaque pointer to the left child node for this node. If no left-child node exists, the value of this member is **NULL**.

### `RightChild`

An opaque pointer to the right child node for this node. If no right-child node exists, the value of this member is **NULL**.

## Remarks

Typically, each node of a splay link tree consists of a user-defined structure. Each such user-defined node must contain an initialized RTL_SPLAY_LINKS structure. To initialize a RTL_SPLAY_LINKS structure, call the [RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks) macro. (Pass the address of the RTL_SPLAY_LINKS member that is contained within the user-defined structure.)

For a splay link tree with one or more nodes, a new node is generally initialized as follows:

1. Use [RtlLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlleftchild) and/or [RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild) to find the insertion point for the new node. That is, obtain the correct address of the parent node for the new node. (The new node will be attached either to the left of the parent node or to the right.)
2. Use [RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks) to initialize the new node with the address of the parent node that is found in the previous step.
3. Insert the new node into the splay tree by using either [RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild) or [RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild), as appropriate.
4. Call [RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay) with the address of the new node. (The new node becomes the root of the splay tree.)

Callers of the **Rtl*****Xxx*** splay tree routines are responsible for synchronizing access to the splay tree. For more information about how to synchronize access to the splay tree, see [Locks, Deadlocks, and Synchronization](https://learn.microsoft.com/previous-versions/ms810047(v=msdn.10)) and [Managing Hardware Priorities](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-hardware-priorities).

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlleftchild)

[RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)