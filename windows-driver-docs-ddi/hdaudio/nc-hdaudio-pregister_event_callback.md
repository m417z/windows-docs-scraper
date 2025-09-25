# PREGISTER_EVENT_CALLBACK callback function

## Description

The *RegisterEventCallback* routine registers a callback routine for an unsolicited response from a codec or codecs.

The function pointer type for a *RegisterEventCallback* routine is defined as follows.

## Parameters

### `_context` [in]

Specifies the context value from the **Context** member of the [HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface), [HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2), or [HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl) structure.

### `Routine` [in]

Function pointer to a callback routine. This parameter must be a valid, non-NULL function pointer of type PHDAUDIO_UNSOLICITED_RESPONSE_CALLBACK. For more information, see the following Remarks section.

### `Context` [in]

Specifies a context value for the callback routine. The caller casts the context value to type PVOID. When a codec generates an unsolicited response that contains the specified tag, the HD Audio bus driver passes the context value to the callback routine as a call parameter.

### `Tag` [out]

Retrieves a tag value that identifies the unsolicited response. This parameter points to a caller-allocated UCHAR variable into which the routine writes the tag value. The caller should specify this tag value when programming the codec or codecs to generate the unsolicited response. For more information, see the following Remarks section.

## Return value

*RegisterEventCallback* returns STATUS_SUCCESS if the call succeeds in registering the event. Otherwise, the routine returns an appropriate error code. The following table shows a possible return status code.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that not enough resources are available to complete the operation. |

## Remarks

This routine registers a callback routine for an unsolicited response from a codec. The routine outputs a tag to identify the unsolicited response. When the HD Audio bus driver encounters an unsolicited response from any codec with a matching tag value, the routine calls the specified callback routine at IRQL DISPATCH_LEVEL and passes the specified context value to the routine as a call parameter.

Following the call to *RegisterEventCallback*, the function driver is responsible for programming the codec or codecs to generate unsolicited responses with the specified tag.

The routine assigns a unique tag to each registered callback routine. The unique association between tag and callback routine persists as long as the callback routine remains registered. The function driver can delete the registration of a callback routine by calling [UnregisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_event_callback).

Currently, the bus driver can supply up to 64 unique tags per codec.

The callback parameter is a function pointer to a callback routine in the function driver. The function pointer type for the callback routine is defined as:

```cpp
typedef VOID
  (*PHDAUDIO_UNSOLICITED_RESPONSE_CALLBACK)
    (HDAUDIO_CODEC_RESPONSE, PVOID);
```

The first call parameter is a structure of type [HDAUDIO_CODEC_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_response) that specifies the codec's response to the command. This structure is passed by value. The second call parameter is the *callbackContext* value that was passed previously to *RegisterEventCallback*. The HD Audio bus driver calls the callback routine at IRQL DISPATCH_LEVEL.

## See also

[HDAUDIO_BUS_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface)

[HDAUDIO_BUS_INTERFACE_BDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_bdl)

[HDAUDIO_BUS_INTERFACE_V2](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_bus_interface_v2)

[HDAUDIO_CODEC_RESPONSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/ns-hdaudio-_hdaudio_codec_response)

[UnregisterEventCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/nc-hdaudio-punregister_event_callback)

[hdaudio.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/hdaudio/)