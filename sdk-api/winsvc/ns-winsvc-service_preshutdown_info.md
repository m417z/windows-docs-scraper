# SERVICE_PRESHUTDOWN_INFO structure

## Description

Contains preshutdown settings.

## Members

### `dwPreshutdownTimeout`

The time-out value, in milliseconds.

## Remarks

Starting with the Windows Creator’s Update (build 15063) the default preshutdown time-out value is 10,000 milliseconds (10 seconds). In prior releases, the default preshutdown time-out value is 180,000 milliseconds (three minutes).

After the service control manager sends the SERVICE_CONTROL_PRESHUTDOWN notification to the [HandlerEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nc-winsvc-lphandler_function_ex) function, it waits for one of the following to occur before proceeding with other shutdown actions: the specified time elapses or the service enters the SERVICE_STOPPED state. The service can continue to update its status for as long as it is in the SERVICE_STOP_PENDING state.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)