# IoWMIWriteEvent function

## Description

The **IoWMIWriteEvent** routine delivers a given event to the user-mode WMI components for notification.

## Parameters

### `WnodeEventItem` [in, out]

Pointer to a [WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item) structure to be delivered to the user-mode WMI components that requested notification of the event.

## Return value

**IoWMIWriteEvent** returns a status code from the following list:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that WMI has successfully queued the event for delivery to the user-mode WMI components. |
| **STATUS_UNSUCCESSFUL** | Indicates that WMI services are unavailable. |
| **STATUS_BUFFER_OVERFLOW** | Indicates that the event item specified exceeds the maximum allowed size. |
| **STATUS_INSUFFICIENT_RESOURCES** | Indicates that insufficient resources were available for WMI to queue the event for delivery. |

## Remarks

The WNODE_EVENT_ITEM structure that is allocated by the caller and passed in *WnodeEventItem* must be allocated from nonpaged pool. If **IoWMIWriteEvent** returns STATUS_SUCCESS, the memory for the event item will automatically be freed by the system. If **IoWMIWriteEvent** returns anything other than STATUS_SUCCESS, it is the caller's responsibility to free the buffer.

Drivers should only call **IoWMIWriteEvent** for events that have been enabled for WMI. This ensures that there is an event consumer waiting for indication on that event.

Callers of this routine must be running at IRQL <= APC_LEVEL, with one exception. When the **Flags** member of the [WNODE_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-_wnode_header) structure contains WNODE_FLAG_TRACED_GUID, **IoWMIWriteEvent** can be called at any IRQL. (The **WNODE_HEADER** structure is a member of the [WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item) structure that the *WnodeEventItem* parameter points to.)

## See also

[IoWMIDeviceObjectToProviderId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmideviceobjecttoproviderid)

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)