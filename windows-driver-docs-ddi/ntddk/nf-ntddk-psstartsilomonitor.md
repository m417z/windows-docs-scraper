# PsStartSiloMonitor function

## Description

This routine tries to start the server silo monitor.

## Parameters

### `Monitor` [in]

A pointer to the silo monitor.

## Return value

The following NT status codes are returned.

| Return code | Description |
| --- | --- |
| **STATUS_REQUEST_ABORTED** | The monitor was not able to start. |
| **STATUS_NOT_SUPPORTED** | The monitor does not allow existing silos and one was found in the system. |
| **STATUS_SUCCESS** | The operation completed successfully. |