# RtlInsertAsRightChild function

## Description

The **RtlInsertAsRightChild** routine inserts a given splay link into the tree as the right child of a given node in that tree.

## Parameters

### `ParentLinks` [in]

Pointer to the node in the tree at which *ChildLinks* should be inserted as the right child.

### `ChildLinks` [in]

Pointer to the splay link node to be inserted into the tree. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

Callers of **RtlInsertAsRightChild** are responsible for meeting the following criteria:

* The node at *ParentLinks* must have no right child.

  A caller can determine whether the node already has a right child by calling **RtlRightChild**. If **RtlRightChild** returns **NULL**, *ParentLinks* is a valid parameter to **RtlInsertAsRightChild**.
* The node at *ChildLinks* must have no parent.

  A caller can determine whether this node already has a parent by calling **RtlIsRoot** or **RtlParent**. If **RtlIsRoot** returns **TRUE** when called with *ChildLinks*, *ChildLinks* is a valid parameter to **RtlInsertAsRightChild**. If **RtlParent** returns an equivalent pointer to *ChildLinks*, *ChildLinks* is also a valid parameter to **RtlInsertAsRightChild**.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlInsertAsRightChild** must be running at IRQL <= DISPATCH_LEVEL if the splay link tree and *ChildLinks* node are nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasleftchild)

[RtlIsRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisroot)

[RtlParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlparent)

[RtlRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrightchild)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)