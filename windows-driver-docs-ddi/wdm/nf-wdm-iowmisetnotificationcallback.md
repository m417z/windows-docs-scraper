## Description

The **IoWMISetNotificationCallback** routine registers a notification callback for a WMI event.

## Parameters

### `Object` [in, out]

Pointer to a WMI data block object. The caller opens the data block object for the WMI event with the [IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock) routine. The object must be opened with the WMIGUID_NOTIFICATION access right.

### `Callback` [in]

Pointer to a function of the form:

```cpp
 XxxWmiNotificationCallback(PVOID Wnode, PVOID Context);
```

WMI calls this function to notify the caller that the specified event has occurred. The *Wnode* parameter of the callback routine points to the [**WNODE_EVENT_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item) structure returned by the driver triggering the event. The *Context* parameter of the callback routine points to the value specified in the *Context* parameter of the **IoWMISetNotificationCallback** routine.

### `Context` [in, optional]

Specifies the value that WMI passes to the callback routine when the event occurs.

## Return value

This routine returns STATUS_SUCCESS on success, and the appropriate NTSTATUS error code on failure.

## See also

[IoWMIOpenBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiopenblock)

[**WNODE_EVENT_ITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)