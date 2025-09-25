## Description

The **EVT_ACX_PIN_RETRIEVE_JACK_SINK_INFO** callback function is implemented by the driver and is called when sink information is requested for the specified pin.

## Parameters

### `Pin`

An [ACXPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/) object representing the specific pin for which sink information is requested.

### `SinkInfo`

A pointer to an [ACX_JACK_SINK_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ns-acxpin-acx_jack_sink_information) structure to be populated with the requested sink information.

## Return value

**EVT_ACX_PIN_RETRIEVE_JACK_SINK_INFO** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)