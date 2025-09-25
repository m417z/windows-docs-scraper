# _KSM_PIN_PAIR structure

## Description

The KSM_PIN_PAIR structure describes a method request to retrieve the pin pairing structure (BDA_PIN_PAIRING) between a pair of input and output pins.

## Members

### `Method`

KSMETHOD structure that describes a method and request type of a method request.

### `InputPinId`

Identifier of an input pin of the filter.

### `OutputPinId`

Identifier of an output pin of the filter.

### `Reserved`

Reserved.

## See also

[BDA_PIN_PAIRING](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdasup/ns-bdasup-_bda_pin_pairing)

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)