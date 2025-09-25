# IWTSSBPlugin::Terminated

## Description

[The [IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin) interface is
not supported after Windows Server 2008 R2. Starting with Windows Server 2012 please use the
[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin) interface.]

 Notifies the plug-in that it is about to be destroyed by Terminal Services Session Broker (TS Session Broker).

## Return value

Returns **S_OK** if successful.

## Remarks

TS Session Broker calls this method before it destroys this instance of the plug-in. You can use this method to perform cleanup for the plug-in before TS Session Broker destroys it. After the plug-in is destroyed, TS Session Broker reverts to its native redirection service.

Your implementation of this method must return **S_OK** immediately if successful.

## See also

[ITsSbPlugin](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbplugin)

[IWTSSBPlugin](https://learn.microsoft.com/windows/desktop/api/tssbx/nn-tssbx-iwtssbplugin)