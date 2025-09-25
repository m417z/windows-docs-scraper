# CM_NOTIFY_FILTER structure

## Description

Device notification filter structure

## Members

### `cbSize`

The size of the structure.

### `Flags`

A combination of zero or more of the following flags:

#### CM_NOTIFY_FILTER_FLAG_ALL_INTERFACE_CLASSES

Register to receive notifications for PnP events for all device interface classes. The memory at **pFilter->u.DeviceInterface.ClassGuid** must be zeroes. Do not use this flag with CM_NOTIFY_FILTER_FLAG_ALL_DEVICE_INSTANCES. This flag is only valid if **pFilter->FilterType** is CM_NOTIFY_FILTER_TYPE_DEVICEINTERFACE.

#### CM_NOTIFY_FILTER_FLAG_ALL_DEVICE_INSTANCES

Register to receive notifications for PnP events for all devices. **pFilter->u.DeviceInstance.InstanceId** must be an empty string. Do not use this flag with CM_NOTIFY_FILTER_FLAG_ALL_INTERFACE_CLASSES. This flag is only valid if **pFilter->FilterType** is CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE.

### `FilterType`

Must be one of the following values:

#### CM_NOTIFY_FILTER_TYPE_DEVICEINTERFACE

Register for notifications for device interface events. **pFilter->u.DeviceInterface.ClassGuid** should be filled in with the GUID of the device interface class to receive notifications for.

#### CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE

Register for notifications for device handle events. **pFilter->u.DeviceHandle.hTarget** must be filled in with a handle to the device to receive notifications for. This handle must remain a valid handle to the device for the duration of the [CM_Register_Notification](https://learn.microsoft.com/windows/win32/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) call. However, after CM_Register_Notification returns, the handle can be closed without affecting the ability for the registration to receive notifications.

#### CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE

Register for notifications for device instance events. **pFilter->u.DeviceInstance.InstanceId** should be filled in with the device instance ID of the device to receive notifications for.

### `Reserved`

Set to 0.

### `u`

A union that contains information about the device to receive notifications for.

### `u.DeviceInterface`

### `u.DeviceInterface.ClassGuid`

The GUID of the device interface class for which to receive notifications.

### `u.DeviceHandle`

A handle to the device for which to receive notifications.

### `u.DeviceHandle.hTarget`

### `u.DeviceInstance`

The device instance ID for the device for which to receive notifications.

### `u.DeviceInstance.InstanceId`

## Remarks

When the driver calls the [CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) function, it supplies a pointer to a **CM_NOTIFY_FILTER** structure in the *pFilter* parameter.

## See also

[CM_NOTIFY_ACTION](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ne-cfgmgr32-cm_notify_action)

[CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification)