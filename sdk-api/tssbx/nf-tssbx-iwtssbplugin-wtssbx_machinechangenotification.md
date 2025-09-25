# IWTSSBPlugin::WTSSBX_MachineChangeNotification

## Description

[The [IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin) interface is
not supported after Windows Server 2008 R2. Starting with Windows Server 2012 please use the
[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin) interface.]

Notifies the plug-in that a change occurred in the server environment.

## Parameters

### `NotificationType` [in]

A value of the [WTSSBX_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/win32/api/tssbx/ne-tssbx-wtssbx_notification_type) enumeration type that indicates the type of event that occurred.

### `MachineId` [in]

The ID of the server on which the change occurred.

### `pMachineInfo` [in]

A pointer to a [WTSSBX_MACHINE_INFO](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_machine_info) structure that contains information about the server that changed. Only the members that changed are reported in this structure. The other members are set to zero.

## Return value

Returns **S_OK** if successful.

## Remarks

Terminal Services Session Broker (TS Session Broker) calls this method whenever an important change in the server environment occurs. For example, changes that would trigger a call include when:

* A server joins or leaves a farm in TS Session Broker.
* A server changes its drain state.
* A server IP address changes.
* A server's maximum session limit changes.

Your implementation of this method must return **S_OK** immediately if successful.

## See also

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)