# KSM_NODE structure

## Description

Just as [KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node) is used for properties on a node, the KSM_NODE structure is used for methods on a node.

## Members

### `Method`

A structure of type [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) that specifies the requested method.

### `NodeId`

Specifies the node ID.

### `Reserved`

Reserved for system use. Should be set to zero.

## See also

[KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node)