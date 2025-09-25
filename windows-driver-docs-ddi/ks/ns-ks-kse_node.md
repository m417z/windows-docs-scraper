# KSE_NODE structure

## Description

The KSE_NODE structure specifies an event request on a specific node.

## Members

### `Event`

A structure of type [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) that identifies the requested event.

### `NodeId`

Specifies the node ID.

### `Reserved`

Reserved for system use. Should be set to zero.

## See also

[KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node)