# _RECORDER_LOG_CREATE_PARAMS structure

## Description

The **RECORDER_LOG_CREATE_PARAMS** structure is an input parameter to the [WppRecorderLogCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderlogcreate) method.

## Members

### `Size`

 Size of this structure.

### `LogTag`

 Optional tag to associate with the allocated memory of the log.

### `TotalBufferSize`

Size in bytes for the log area.

### `ErrorPartitionSize`

 The number of bytes out of **TotalBufferSize** used to log error messages. Zero indicates no error partition.

### `LogIdentifierAppendValue`

 Number/pointer to append to log identifier.

### `LogIdentifierAppendValueSet`

 Specifies whether **LogIdentifierAppendValue** has been set.

### `LogIdentifierSize`

 Size of **LogIdentifier** field, in bytes (according to client's definition).

### `LogIdentifier`

Identifier to print when debug messages are merged. Lives at end of structure so that, if at some point clients have different definitions of the array size, it remains simple to read the rest of the structure.

### `UseTimeStamp`

A [WPP_RECORDER_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ne-wpprecorder-wpp_recorder_tri_state)-typed value that indicates:

* If set to **WppRecorderTrue**, timestamps of millisecond granularity will be added to WPP log entries.
* If set to **WppRecorderFalse**, the timestamp will not be recorded.
* If set to **WppRecorderDefault**, it has the same effect as **WppRecorderFalse**, unless the INF file for the driver package sets **WppRecorder_UseTimeStamp** to 1, in which case it means **WppRecorderTrue**.

This field is available starting in Windows 11, version 22H2. For more info, see [Inflight Trace Recorder (IFR) for logging traces](https://learn.microsoft.com/windows-hardware/drivers/devtest/using-wpp-recorder).

### `PreciseTimeStamp`

A [WPP_RECORDER_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ne-wpprecorder-wpp_recorder_tri_state)-typed value that indicates:

* If set to **WppRecorderTrue**, timestamps of a tenth of a microsecond granularity will be added to WPP log entries.
* If set to **WppRecorderFalse**, the timestamp will not be recorded.
* If set to **WppRecorderDefault**, it has the same effect as **WppRecorderFalse**, unless the INF file for the driver package sets **WppRecorder_UseTimeStamp** and **WppRecorder_PreciseTimeStamp** to 1, in which case it means **WppRecorderTrue**.

This field is available starting in Windows 11, version 22H2. For more info, see [Inflight Trace Recorder (IFR) for logging traces](https://learn.microsoft.com/windows-hardware/drivers/devtest/using-wpp-recorder).

## See also

[RECORDER_LOG_CREATE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-recorder_log_create_params_init)