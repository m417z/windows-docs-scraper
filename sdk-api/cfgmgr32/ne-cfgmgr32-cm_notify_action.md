# CM_NOTIFY_ACTION enumeration

## Description

This enumeration identifies Plug and Play device event types.

## Constants

### `CM_NOTIFY_ACTION_DEVICEINTERFACEARRIVAL:0`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEINTERFACE**. This action indicates that a device interface that meets your filter criteria has been enabled.

### `CM_NOTIFY_ACTION_DEVICEINTERFACEREMOVAL`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEINTERFACE**.

 This action indicates that a device interface that meets your filter criteria has been disabled.

### `CM_NOTIFY_ACTION_DEVICEQUERYREMOVE`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE**.

 This action indicates that the device is being query removed. In order to allow the query remove to succeed, call [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) to close any handles you have open to the device. If you do not do this, your open handle prevents the query remove of this device from succeeding. See [Registering for Notification of Device Interface Arrival and Device Removal](https://learn.microsoft.com/windows-hardware/drivers/install/registering-for-notification-of-device-interface-arrival-and-device-removal) for more information.

To veto the query remove, return ERROR_CANCELLED. However, it is recommended that you do not veto the query remove and allow it to happen by closing any handles you have open to the device.

### `CM_NOTIFY_ACTION_DEVICEQUERYREMOVEFAILED`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE**.

 This action indicates that the query remove of a device was failed. If you closed the handle to this device during a previous notification of **CM_NOTIFY_ACTION_DEVICEQUERYREMOVE**, open a new handle to the device to continue sending I/O requests to it. See [Registering for Notification of Device Interface Arrival and Device Removal](https://learn.microsoft.com/windows-hardware/drivers/install/registering-for-notification-of-device-interface-arrival-and-device-removal) for more information.

### `CM_NOTIFY_ACTION_DEVICEREMOVEPENDING`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE**.

The device will be removed. If you still have an open handle to the device, call [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) to close the device handle. See [Registering for Notification of Device Interface Arrival and Device Removal](https://learn.microsoft.com/windows-hardware/drivers/install/registering-for-notification-of-device-interface-arrival-and-device-removal) for more information. The system may send a **CM_NOTIFY_ACTION_DEVICEREMOVEPENDING** notification without sending a corresponding **CM_NOTIFY_ACTION_DEVICEQUERYREMOVE** message. In such cases, the applications and drivers must recover from the loss of the device as best they can.

### `CM_NOTIFY_ACTION_DEVICEREMOVECOMPLETE`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE**.

The device has been removed. If you still have an open handle to the device, call [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) to close the device handle. See [Registering for Notification of Device Interface Arrival and Device Removal](https://learn.microsoft.com/windows-hardware/drivers/install/registering-for-notification-of-device-interface-arrival-and-device-removal) for more information. The system may send a **CM_NOTIFY_ACTION_DEVICEREMOVECOMPLETE** notification without sending corresponding **CM_NOTIFY_ACTION_DEVICEQUERYREMOVE** or **CM_NOTIFY_ACTION_DEVICEREMOVEPENDING** messages. In such cases, the applications and drivers must recover from the loss of the device as best they can.

### `CM_NOTIFY_ACTION_DEVICECUSTOMEVENT`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEHANDLE**. This action is sent when a driver-defined custom event has occurred.

### `CM_NOTIFY_ACTION_DEVICEINSTANCEENUMERATED`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE**. This action is sent when a new device instance that meets your filter criteria has been enumerated.

### `CM_NOTIFY_ACTION_DEVICEINSTANCESTARTED`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE**. This action is sent when a device instance that meets your filter criteria becomes started.

### `CM_NOTIFY_ACTION_DEVICEINSTANCEREMOVED`

For this value, set the **FilterType** member of the [CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter) structure
to **CM_NOTIFY_FILTER_TYPE_DEVICEINSTANCE**. This action is sent when a device instance that meets your filter criteria is no longer present.

### `CM_NOTIFY_ACTION_MAX`

Do not use.

## Remarks

When a driver calls the [CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification) function, the *pCallback* parameter contains a pointer to a routine to be called when a specified PnP event occurs. The callback routine's *Action* parameter is a value from the **CM_NOTIFY_ACTION** enumeration.

## See also

[CM_NOTIFY_FILTER](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/ns-cfgmgr32-cm_notify_filter)

[CM_Register_Notification](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_register_notification)