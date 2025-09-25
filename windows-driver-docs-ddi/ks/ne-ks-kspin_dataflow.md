# KSPIN_DATAFLOW enumeration

## Description

An instance of the KSPIN_DATAFLOW enumeration is returned by [KSPROPERTY_PIN_DATAFLOW](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataflow).

## Constants

### `KSPIN_DATAFLOW_IN`

Indicates that the pin factory instantiates data sink pins. Such pins can only be connected to data source pins.

### `KSPIN_DATAFLOW_OUT`

Indicates that the pin factory instantiates data source pins. Such pins can only be connected to data sink pins.

## See also

[HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KSPIN_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)