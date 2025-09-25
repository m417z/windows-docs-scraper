# PUNREGISTER_EVENT_CALLBACK callback function

## Description

The *UnregisterEventCallback* routine deletes the registration of an event callback that was previously registered by a call to [RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback).

The function pointer type for an *UnregisterEventCallback* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Tag` [in]

Specifies the tag value that was associated with the callback by the preceding call to [RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback).

## Return value

*UnregisterEventCallback* returns STATUS_SUCCESS if the call succeeds in changing the DMA engines' states. Otherwise, the routine returns an appropriate error code. The following table shows a possible return status code.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | Indicates that the specified tag is not valid. |

## Remarks

Before calling this routine, the function driver is responsible for programming the codec or codecs to remove the association of the callback with the specified tag.

## See also

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[RegisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-pregister_event_callback)
[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)