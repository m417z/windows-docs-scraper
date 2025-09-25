# IWTSSBPlugin::WTSSBX_GetUserExternalSession

## Description

[The [IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin) interface is
not supported after Windows Server 2008 R2. Starting with Windows Server 2012 please use the
[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin) interface.]

Redirects an incoming connection to a computing resource, such as a virtual machine, a blade server, or even the user's own corporate desktop by providing a [WTSSBX_MACHINE_CONNECT_INFO](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_machine_connect_info) structure that contains information about the resource.

## Parameters

### `UserName` [in]

A pointer to a Unicode string that contains the user name of the incoming connection.

### `DomainName` [in]

A pointer to a Unicode string that contains the domain name of the incoming connection.

### `ApplicationType` [in]

A pointer to a Unicode string that contains the program that Remote Desktop Services runs after the user session is created.

### `RedirectorInternalIP` [in]

A pointer to the internal IP address of the RD Session Host server that first accepted the connection.

### `pSessionId` [out]

A pointer to the session ID of the session to which the plug-in is redirecting the incoming connection.

### `pMachineConnectInfo` [out]

A pointer to a [WTSSBX_MACHINE_CONNECT_INFO](https://learn.microsoft.com/windows/win32/api/tssbx/ns-tssbx-wtssbx_machine_connect_info) structure that contains information about the computer to which the plug-in is directing the incoming connection.

## Return value

Returns **S_OK** if successful.

## Remarks

Terminal Services Session Broker (TS Session Broker) calls this method so that the plug-in can redirect an incoming connection to a computer that is not joined to a farm in TS Session Broker.

Your implementation of **WTSSBX_GetUserExternalSession** should return **E_NOTIMPL** if it does not support redirection to computers that are not joined to farms in TS Session Broker.

## See also

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)