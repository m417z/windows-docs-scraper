# _BDA_PIN_PAIRING structure

## Description

The BDA_PIN_PAIRING structure describes the topology between a pair of input and output pins.

## Members

### `ulInputPin`

Index of the element in the zero-based array of pin types (KSPIN_DESCRIPTOR_EX array) that indicates the input pin of the pair.

### `ulOutputPin`

Index of the element in the zero-based array of pin types (KSPIN_DESCRIPTOR_EX array) that indicates the output pin of the pair.

### `ulcMaxInputsPerOutput`

Maximum number of input pins per output pin. The network provider creates duplicates of nodes that are controlled by the input pin depending on the value specified in **ulcMaxInputsPerOutput**.

### `ulcMinInputsPerOutput`

Minimum number of input pins per output pin. The network provider creates duplicates of nodes that are controlled by the input pin depending on the value specified in **ulcMinInputsPerOutput**.

### `ulcMaxOutputsPerInput`

Maximum number of output pins per input pin. The network provider creates duplicates of nodes that are controlled by the output pin depending on the value specified in **ulcMaxOutputsPerInput**.

### `ulcMinOutputsPerInput`

Minimum number of output pins per input pin. The network provider creates duplicates of nodes that are controlled by the output pin depending on the value specified in **ulcMinOutputsPerInput**.

### `ulcTopologyJoints`

Number of joints in the **pTopologyJoints** array.

### `pTopologyJoints`

Array of joint values. The value given to a joint corresponds to the index of an element in an array of template connections (KSTOPOLOGY_CONNECTION or BDA_TEMPLATE_CONNECTION array). A topology joint marks the point in the template topology where control of nodes switches from the input pin to the output pin. Those nodes that occur upstream of the topology joint are controlled through the input pin. Those nodes that occur downstream of the topology joint are controlled through the output pin.

## See also

[BDA_FILTER_TEMPLATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_filter_template)

[BDA_TEMPLATE_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdatypes/ns-bdatypes-_bda_template_connection)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSTOPOLOGY_CONNECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)