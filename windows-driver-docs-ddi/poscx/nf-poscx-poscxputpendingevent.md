## Description

PosCxPutPendingEvent creates a new event object, copies the event data to the new event object, and tries to delegate it to the waiting caller. If the target caller does not have a read request waiting, the new event is added to the designated event queue (control or data).

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `deviceInterfaceTag` [in]

The device interface associated with the event. By default, only file objects that have the same tag will receive this event.

### `eventType` [in]

The new event type.

### `rawEventDataSize` [in]

The raw event (without point-of-service header) buffer size in bytes.

### `rawEventDataPtr`

The pointer to the raw (without point-of-service header) event data. The caller may reuse/release *rawEventDataPtr* after **PosCxPutPendingEvent** returns.

### `eventAttr` [in]

The event attributes.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | The event was created and delegated to a waiting caller, or the event was discarded because there is no device owner. |
| **STATUS_PENDING** | The event was queued because no caller is currently waiting. |
| Other errors | Other appropriate failure error codes. |

## See also

[POS_CX_EVENT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ne-poscx-_pos_cx_event_attributes)