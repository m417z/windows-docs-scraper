# _KSP_BDA_NODE_PIN structure

## Description

The KSP_BDA_NODE_PIN structure describes a property request to retrieve the controlling pin for a node.

## Members

### `Property`

KSPROPERTY structure that describes the property and request type of the property request.

### `ulNodeType`

Index of the element in the zero-based array of internal node types (KSNODE_DESCRIPTOR array) that specifies the node type for which to retrieve the controlling pin.

### `ulInputPinId`

Identifier of an input pin of the filter.

### `ulOutputPinId`

Identifier of an output pin of the filter.

## See also

[BdaPropertyGetControllingPinId](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdapropertygetcontrollingpinid)

[KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)