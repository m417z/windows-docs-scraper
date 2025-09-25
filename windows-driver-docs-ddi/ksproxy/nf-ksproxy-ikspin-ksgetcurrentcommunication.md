## Description

The **KsGetCurrentCommunication** method retrieves the current communication direction, interface, and medium of a pin.

## Parameters

### `Communication` [out, optional]

Pointer to a variable that receives one of the following values from the KSPIN_COMMUNICATION enumerated type describing the current communication direction for a pin:

| Value | Description |
|---|---|
| KSPIN_COMMUNICATION_NONE | The pin factory does not create any pin instances. |
| KSPIN_COMMUNICATION_SINK | The pin factory creates instances of IRP sink pins. Such pins can only be connected to IRP source pins. |
| KSPIN_COMMUNICATION_SOURCE | The pin factory creates instances of IRP source pins. Such pins can only be connected to IRP sink pins. |
| KSPIN_COMMUNICATION_BOTH | The pin factory creates instances of pins that are both IRP sinks and IRP sources. |
| KSPIN_COMMUNICATION_BRIDGE | The pin cannot connect to other pins, but instances may be created on it to receive non-KS I/O requests. |

### `Interface` [out, optional]

Pointer to a variable that receives a [KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure) structure that describes the current interface for a pin.

### `Medium` [out, optional]

Pointer to a variable that receives a [KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure) structure that describes the current medium for a pin.

## Return value

Returns NOERROR if successful; otherwise, returns an error code.

## Remarks

Source pins send IRPs to sink pins. Do not confuse the communication direction with data flow direction. (See [KSPROPERTY_PIN_DATAFLOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataflow).) A source pin may read or write data, and a sink pin may have data read to it or written from it.

The current communication direction, interface, and medium of a pin are a subset of those available to the pin, and are selected when the pin handle is created.

## See also

[KSPIN_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-interface-structure)

[KSPIN_MEDIUM](https://learn.microsoft.com/windows-hardware/drivers/stream/kspin-medium-structure)

[KSPROPERTY_PIN_DATAFLOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataflow)