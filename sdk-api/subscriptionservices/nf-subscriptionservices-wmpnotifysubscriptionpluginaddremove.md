# WMPNotifySubscriptionPluginAddRemove function

## Description

The **WMPNotifySubscriptionPluginAddRemove** function notifies Windows Media Player that a COM object has been installed or uninstalled.

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

## Return value

The return value indicates whether the function call succeeded.

## Remarks

This function is typically called by a plug-in in its [DllRegisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllregisterserver) and [DllUnregisterServer](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-dllunregisterserver) methods. It alerts Windows Media Player to enumerate registered online store objects.

## See also

[Reference for Type 2 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/reference-for-type-2-online-stores)