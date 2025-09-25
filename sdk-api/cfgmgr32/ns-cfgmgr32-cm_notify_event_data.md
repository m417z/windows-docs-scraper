# CM_NOTIFY_EVENT_DATA structure

## Description

This is a device notification event data structure.

## Members

### `FilterType`

The **CM_NOTIFY_FILTER_TYPE** from the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure that was used in the registration that generated this notification event data.

### `Reserved`

Reserved. Must be 0.

### `u`

A union that contains information about the notification event data. To determine which member of the union to examine, check the **FilterType** of the event data.

### `u.DeviceInterface`

Examine this part of the union when the **FilterType** is **CM_NOTIFY_FILTER_TYPE_DEVICEINTERFACE**.

### `u.DeviceInterface.ClassGuid`

The GUID of the device interface class for the device interface to which the notification event data pertains.

### `u.DeviceInterface.SymbolicLink`

The symbolic link path of the device interface to which the notification event data pertains.

### `u.DeviceHandle`

Examine this part of the union when the **FilterType** is **CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE** and the notification action is **CM_NOTIFY_ACTION_DEVICECUSTOMEVENT**.

### `u.DeviceHandle.EventGuid`

The GUID for the custom event.

### `u.DeviceHandle.NameOffset`

The offset of an optional string buffer. Usage depends on the contract for the **EventGuid**.

### `u.DeviceHandle.DataSize`

The number of bytes that can be read from the **Data** member.

### `u.DeviceHandle.Data`

Optional binary data. Usage depends on the contract for the **EventGuid**.

### `u.DeviceInstance`

Examine this part of the union when the **FilterType** is **CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE**.

### `u.DeviceInstance.InstanceId`

The device instance ID of the device to which the notification event data pertains.

## Remarks

The notification callback supplied to [CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) receives a pointer to a structure of type **CM_NOTIFY_EVENT_DATA** in the callback's *EventData* parameter.

## See also

[CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification)