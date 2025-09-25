## Description

This routine registers a server silo monitor that can receive notifications about server silo events.

To start receiving notifications, call the [PsStartSiloMonitor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psstartsilomonitor) routine.

## Parameters

### `Registration` [in]

Specifies the server silo monitor to be registered, of type [**SILO_MONITOR_REGISTRATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_silo_monitor_registration).

### `ReturnedMonitor` [out]

Receives a pointer to the monitor. This pointer is used to make further monitor-related calls.

## Return value

The following NT status codes are returned:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER** | The version specified in **ntddk.h** does not match **SILO_MONITOR_REGISTRATION_VERSION**, the component name is not specified, or the terminate callback is not supplied. |
| **STATUS_PRIVILEDGE_NOT_HELD** | The routine is called in a silo. |
| **STATUS_INSUFFICIENT_RESOURCES** | There is no memory to register a silo monitor or there is no available silo slot. |
| **STATUS_SUCCESS** | The operation completed successfully. |