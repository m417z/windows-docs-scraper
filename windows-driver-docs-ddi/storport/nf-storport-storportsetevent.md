# StorPortSetEvent function

## Description

A miniport can call **StorPortSetEvent** to set an event object to the signaled state.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport's device extension.

### `Event`

Pointer to a [**STOR_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event) structure containing the event object.

## Return value

**StorPortSetEvent** returns a status code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_INVALID_IRQL | The current IRQL is greater than DISPATCH_LEVEL. |
| STOR_STATUS_INVALID_PARAMETER | Either *HwDeviceExtension* or *Event* are invalid parameters. |
| STOR_STATUS_SUCCESS | The event object was successfully set to the signaled state. |
| STOR_STATUS_UNSUCCESSFUL | The operation failed. |

## Remarks

See [**KeSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent) for more details.

## See also

[**KeSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent) for more details.

[**STOR_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event)

[**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent)