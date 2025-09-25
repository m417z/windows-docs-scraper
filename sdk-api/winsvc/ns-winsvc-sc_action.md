# SC_ACTION structure

## Description

Represents an action that the service control manager can perform.

## Members

### `Type`

The action to be performed. This member can be one of the following values from the **SC_ACTION_TYPE** enumeration type.

| Value | Meaning |
| --- | --- |
| **SC_ACTION_NONE**<br><br>0 | No action. |
| **SC_ACTION_REBOOT**<br><br>2 | Reboot the computer. |
| **SC_ACTION_RESTART**<br><br>1 | Restart the service. |
| **SC_ACTION_RUN_COMMAND**<br><br>3 | Run a command. |

### `Delay`

The time to wait before performing the specified action, in milliseconds.

## Remarks

This structure is used by the
[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) and
[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a) functions, in the
[SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsa) structure.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)

[SERVICE_FAILURE_ACTIONS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_failure_actionsa)