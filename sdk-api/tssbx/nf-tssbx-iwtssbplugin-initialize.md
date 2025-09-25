# IWTSSBPlugin::Initialize

## Description

[The [IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin) interface is
not supported after Windows Server 2008 R2. Starting with Windows Server 2012 please use the
[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin) interface.]

Initializes the plug-in and returns a value that indicates the redirection capabilities of the
plug-in. Terminal Services Session Broker (TS Session Broker) calls this method
immediately after it instantiates the plug-in class.

## Parameters

### `PluginCapabilities` [out]

A pointer to a value that indicates the redirection capabilities of the plug-in.

#### 0

The plug-in redirects only within a farm in TS Session Broker. If this value is returned, TS Session Broker does not call the [WTSSBX_GetUserExternalSession](https://learn.microsoft.com/windows/desktop/api/tssbx/nf-tssbx-iwtssbplugin-wtssbx_getuserexternalsession) method on the plug-in.

#### 1

The plug-in redirects within a farm in TS Session Broker, and the plug-in implements [WTSSBX_GetUserExternalSession](https://learn.microsoft.com/windows/desktop/api/tssbx/nf-tssbx-iwtssbplugin-wtssbx_getuserexternalsession) to redirect outside the farm.

## Return value

Returns **S_OK** if successful.

## Remarks

TS Session Broker calls **Initialize** immediately after it instantiates the COM class. The plug-in should return information about its redirection capabilities by using the **Initialize** method.

Your implementation of **Initialize** must return **S_OK** immediately if successful.

## See also

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)