# RtlInsertAsLeftChild function

## Description

The **RtlInsertAsLeftChild** routine inserts a splay link node into the tree as the left child of the specified node.

## Parameters

### `ParentLinks` [in]

Pointer to the node in the tree at which *ChildLinks* should be inserted as the left child.

### `ChildLinks` [in]

Pointer to the splay link node to be inserted into the tree. The node must have been initialized by calling **RtlInitializeSplayLinks**.

## Remarks

Callers of **RtlInsertAsLeftChild** are must meet the following criteria:

* The node at *ParentLinks* must have no left child.

  A caller can determine whether the node already has a left child by calling **RtlLeftChild**. If **RtlLeftChild** returns **NULL**, *ParentLinks* is a valid parameter to **RtlInsertAsLeftChild**.
* The node at *ChildLinks* must have no parent.

  A caller can determine whether this node already has a parent by calling **RtlIsRoot** or **RtlParent**. If **RtlIsRoot** returns **TRUE** when called with *ChildLinks*, *ChildLinks* is a valid parameter to **RtlInsertAsLeftChild**. If **RtlParent** returns an equivalent pointer to *ChildLinks*, *ChildLinks* is a valid parameter to **RtlInsertAsLeftChild**.

Callers of the **Rtl** splay link routines are responsible for synchronizing access to the splay link tree. A fast mutex is the most efficient synchronization mechanism to use for this purpose.

Callers of **RtlInsertAsLeftChild** must be running at IRQL <= DISPATCH_LEVEL if the splay link tree and *ChildLinks* node are nonpaged. Usually, callers are running at IRQL PASSIVE_LEVEL.

## See also

[RtlInitializeSplayLinks](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinitializesplaylinks)

[RtlInsertAsRightChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlinsertasrightchild)

[RtlIsRoot](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlisroot)

[RtlLeftChild](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlleftchild)

[RtlParent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlparent)

[RtlSplay](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlsplay)