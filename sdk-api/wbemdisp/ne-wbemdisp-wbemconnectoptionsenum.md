# WbemConnectOptionsEnum enumeration

## Description

The
WbemConnectOptionsEnum constant defines a security flag that is used as a parameter in calls to
the [SWbemLocator.ConnectServer](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemlocator-connectserver) method when a connection to WMI on a remote machine is failing.

## Constants

### `wbemConnectFlagUseMaxWait:0x80`

Shortens the timeout for the [SWbemLocator.ConnectServer](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemlocator-connectserver) method call to two minutes.

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)