## Description

PosCxPutPendingEventMemory tries to delegate a memory object containing the event data to a waiting caller. If the target caller does not have a read request waiting, the new event is added to the designated event queue (control or data).

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `deviceInterfaceTag` [in]

The device interface associated with the event. By default, only file objects that have the same tag will receive this event.

### `eventMemory` [in]

The new event data memory object that contains both the point-of-service event header and the data. PosCx will take over ownership of this passed in memory object.

### `eventAttr` [in]

The event attributes.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | The event was created and delegated to a waiting caller, or the event was discarded because there is no device owner. |
| **STATUS_PENDING** | The event was queued because no caller is currently waiting. |
| **STATUS_DEVICE_NOT_READY** | The PosCx library was not successfully initialized. |
| Other errors | Other appropriate failure error codes. |

## See also

[POS_CX_EVENT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/ne-poscx-_pos_cx_event_attributes)