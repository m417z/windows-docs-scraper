# KSP_NODE structure

## Description

Kernel streaming clients use the KSP_NODE structure to specify the property and node type within a KSPROPERTY_TOPOLOGY_NAME property request.

## Members

### `Property`

Specifies a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure.

### `NodeId`

Specifies the node ID.

### `Reserved`

Reserved for system use. Should be set to zero.

## See also

[KSNODEPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)