# WbemTimeout enumeration

## Description

The
WbemTimeout constant defines the time-out constants. This constant is used by
[SWbemEventSource.NextEvent](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemeventsource-nextevent).

The WMI scripting type library, wbemdisp.tlb, defines these constants. Visual Basic applications can access this library; script languages must use the value of the constant directly, unless they use Windows Script Host (WSH) XML file format. For more information, see
[Using the WMI Scripting Type Library](https://learn.microsoft.com/windows/desktop/WmiSdk/using-the-wmi-scripting-type-library).

## Constants

### `wbemTimeoutInfinite:0xffffffff`

Use for parameters that use a time-out value such as *iTimeoutMs* for [ISWbemServices.ExecNotificationQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execnotificationquery) and the call will not return unless an event is received.

## See also

[Scripting API Constants](https://learn.microsoft.com/windows/desktop/WmiSdk/scripting-api-constants)