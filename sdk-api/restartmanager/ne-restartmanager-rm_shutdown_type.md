# RM_SHUTDOWN_TYPE enumeration

## Description

 Configures the shut down of applications.

## Constants

### `RmForceShutdown:0x1`

 Forces unresponsive applications and services to shut down after the timeout period. An application that does not respond to a shutdown request by the Restart Manager is forced to shut down after 30 seconds. A service that does not respond to a shutdown request is forced to shut down after 20 seconds. These default times can be changed by modifying the registry keys described in the Remarks section.

### `RmShutdownOnlyRegistered:0x10`

Shuts down applications if and only if all the applications have been registered for restart using the **RegisterApplicationRestart** function. If any processes or services cannot be restarted, then no processes or services are shut down.

## Remarks

The time to wait before initiating a forced shutdown of applications is specified by the following registry key. **HKCU**\**Control Panel**\**Desktop**\**HungAppTimeout**

The time to wait before initiating a forced shutdown of services is specified by the following registry key. **HKLM**\**System**\**CurrentControlSet**\**Control**\**WaitToKillServiceTimeout**

## See also

[RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown)