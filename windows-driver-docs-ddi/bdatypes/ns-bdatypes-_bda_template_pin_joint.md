# _BDA_TEMPLATE_PIN_JOINT structure

## Description

The BDA_TEMPLATE_PIN_JOINT structure describes a joint in a template topology.

## Members

### `uliTemplateConnection`

Index of an element in an array of template connections (KSTOPOLOGY_CONNECTION or BDA_TEMPLATE_CONNECTION array) that represents the joint.

### `ulcInstancesMax`

Maximum number of possible instances of the joint in the template topology.

## See also

[BDA_TEMPLATE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdatypes/ns-bdatypes-_bda_template_connection)

[KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)