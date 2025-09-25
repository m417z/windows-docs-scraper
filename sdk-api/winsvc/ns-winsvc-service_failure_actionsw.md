# SERVICE_FAILURE_ACTIONSW structure

## Description

Represents the action the service controller should take on each failure of a service. A service is considered failed when it terminates without reporting a status of **SERVICE_STOPPED** to the service controller.

To configure additional circumstances under which the failure actions are to be executed, see [SERVICE_FAILURE_ACTIONS_FLAG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actions_flag).

## Members

### `dwResetPeriod`

The time after which to reset the failure count to zero if there are no failures, in seconds. Specify **INFINITE** to indicate that this value should never be reset.

### `lpRebootMsg`

The message to be broadcast to server users before rebooting in response to the **SC_ACTION_REBOOT** service controller action.

If this value is **NULL**, the reboot message is unchanged. If the value is an empty string (""), the reboot message is deleted and no message is broadcast.

This member can specify a localized string using the following format:

@[*path*\]*dllname*,-*strID*

The string with identifier *strID* is loaded from *dllname*; the *path* is optional. For more information, see [RegLoadMUIString](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regloadmuistringa).

**Windows Server 2003 and Windows XP:** Localized strings are not supported until Windows Vista.

### `lpCommand`

The command line of the process for the
[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa) function to execute in response to the **SC_ACTION_RUN_COMMAND** service controller action. This process runs under the same account as the service.

If this value is **NULL**, the command is unchanged. If the value is an empty string (""), the command is deleted and no program is run when the service fails.

### `cActions`

The number of elements in the **lpsaActions** array.

If this value is 0, but **lpsaActions** is not NULL, the reset period and array of failure actions are deleted.

### `cActions.range`

### `cActions.range.0`

### `cActions.range.1024`

### `lpsaActions`

A pointer to an array of
[SC_ACTION](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-sc_action) structures.

If this value is NULL, the **cActions** and **dwResetPeriod** members are ignored.

### `lpsaActions.size_is`

### `lpsaActions.size_is.cActions`

## Remarks

The service control manager counts the number of times each service has failed since the system booted. The count is reset to 0 if the service has not failed for **dwResetPeriod** seconds. When the service fails for the *N*th time, the service controller performs the action specified in element [*N*-1] of the **lpsaActions** array. If *N* is greater than *cActions*, the service controller repeats the last action in the array.

> [!NOTE]
> The winsvc.h header defines SERVICE_FAILURE_ACTIONS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[SC_ACTION](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-sc_action)

[SERVICE_FAILURE_ACTIONS_FLAG](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actions_flag)