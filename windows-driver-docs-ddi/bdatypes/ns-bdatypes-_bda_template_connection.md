# _BDA_TEMPLATE_CONNECTION structure

## Description

The BDA_TEMPLATE_CONNECTION structure describes the template for a BDA connection in terms of where it begins and ends.

## Members

### `FromNodeType`

Index of the element in the zero-based array of internal node types (KSNODE_DESCRIPTOR array) that indicates the node type where the connection begins or −1 to indicate that the connection begins at an upstream filter.

### `FromNodePinType`

Index of the element in the zero-based array of pin types (KSPIN_DESCRIPTOR_EX array) that indicates the pin type where the connection begins. The array of pin types is the list of pin types that are available in the filter's template topology.

### `ToNodeType`

Index of the element in the zero-based array of internal node types (KSNODE_DESCRIPTOR array) that indicates the node type where the connection ends or −1 to indicate that the connection ends at a downstream filter.

### `ToNodePinType`

Index of the element in the zero-based array of pin types (KSPIN_DESCRIPTOR_EX array) that indicates the pin type where the connection ends. The array of pin types is the list of pin types that are available in the filter's template topology.

## See also

[BDA_PIN_PAIRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_pin_pairing)

[BdaPropertyTemplateConnections](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/nf-bdasup-bdapropertytemplateconnections)

[KSNODE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPROPSETID_BdaTopology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatopology)

[KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)