# IWTSSBPlugin::WTSSBX_GetMostSuitableServer

## Description

[The [IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin) interface is
not supported after Windows Server 2008 R2. Starting with Windows Server 2012 please use the
[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin) interface.]

Returns the ID of the server to which Terminal Services Session Broker (TS Session Broker) should direct the incoming connection. The redirection logic of the plug-in determines the preferred server.

## Parameters

### `UserName` [in]

A pointer to a Unicode string that contains the user name of the incoming connection.

### `DomainName` [in]

A pointer to a Unicode string that contains the domain name that is associated with the incoming connection.

### `ApplicationType` [in]

A pointer to a Unicode string that contains the name of the program that Remote Desktop Services runs after it creates the session.

### `FarmName` [in]

A pointer to a Unicode string that contains the name of the farm in TS Session Broker that the user is connecting to.

### `pMachineId` [in, out]

A pointer to the ID of the server to which TS Session Broker will redirect the incoming connection. This value is initially set to the ID of the server provided by the load balancing logic of TS Session Broker.

## Return value

Returns **S_OK** if successful.

## Remarks

Use **WTSSBX_GetMostSuitableServer** to override the default load balancing logic of TS Session Broker. TS Session Broker calls this method after it runs its own load balancing logic. The *pMachineId* parameter is initially set to the ID of the server provided by the load balancing logic of TS Session Broker. When you implement this method, your redirection logic can return this *pMachineId* or another one as appropriate.

Whenever a server joins a farm in TS Session Broker, TS Session Broker calls the [WTSSBX_MachineChangeNotification](https://learn.microsoft.com/windows/desktop/api/tssbx/nf-tssbx-iwtssbplugin-wtssbx_machinechangenotification) method to notify the plug-in and provide a MachineId to identify the new server. When TS Session Broker calls **WTSSBX_GetMostSuitableServer**, the plug-in should return one of the IDs that TS Session Broker provided to the plug-in. The plug-in should not return the ID of a server that is not in the farm.

Your implementation of **WTSSBX_GetMostSuitableServer** must return **S_OK** immediately if successful.

## See also

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)