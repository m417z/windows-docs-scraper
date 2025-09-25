# KSNODEPROPERTY structure

## Description

The KSNODEPROPERTY structure specifies a node and a property of that node.

## Members

### `Property`

Specifies the property to get or set. This member is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `NodeId`

Specifies the node ID. This member identifies the target node for the property request.

### `Reserved`

Reserved for internal use by operating system. Do not use.

## Remarks

This structure is identical to [KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node).

See the discussion of the KSNODEPROPERTY structure in [Audio Property Requests](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-property-requests).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node)