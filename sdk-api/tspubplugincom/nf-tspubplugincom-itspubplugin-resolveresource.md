# ItsPubPlugin::ResolveResource

## Description

 Provides information about how to connect to a user's assigned personal virtual desktop. Implement this method if you want to provide a custom implementation of the personal virtual desktop functionality.

Otherwise, this method should return **E_NOTIMPL**. This method is called by the RemoteApp and Desktop Connection Management service when Remote Desktop Connection Broker (RD Connection Broker) is connecting a user to a personal virtual desktop.

## Parameters

### `resourceType` [out]

A pointer to a **DWORD** variable to receive the type of resource. This can be one of the following values.

#### 1

The plug-in is for virtual desktop pools.

#### 2

The plug-in is for personal virtual desktops.

### `resourceLocation` [out]

The name of the resource plug-in.

### `endPointName` [out]

The name of the endpoint. For personal virtual desktops, specify the name of the desktop assigned to the user. For virtual desktop pools, specify the name of the pool.

### `userID` [in]

A pointer to a string that contains the user security identifier (SID).

### `alias` [in]

A pointer to a string that contains the alias of the user.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

RD Connection Broker only calls one plug-in when connecting a user to a resource. To receive calls, you must register your plug-in before starting RD Connection Broker, or you must add a "LoadBalanceInfo" setting to the .rdp file that the client uses to connect. For example, if your plug-in is for personal virtual desktops and is called "plugin1", you would add the following line to the .rdp file: "LoadBalanceInfo:s:tsv://vmresource1.2.plugin1"

## See also

[ItsPubPlugin](https://learn.microsoft.com/windows/desktop/api/tspubplugincom/nn-tspubplugincom-itspubplugin)