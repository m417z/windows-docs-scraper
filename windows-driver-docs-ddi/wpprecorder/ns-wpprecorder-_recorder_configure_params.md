# _RECORDER_CONFIGURE_PARAMS structure

## Description

The **RECORDER_CONFIGURE_PARAMS** structure is an input parameter to the [WppRecorderConfigure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderconfigure) method to enable or disable the default log to which WPP prints.

## Members

### `Size`

Size of this structure.

### `CreateDefaultLog`

Indicates whether WPP should use the default log for trace messages. TRUE (default), use the default log; FALSE disable the default log.

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

## Remarks

To initialize this structure, the caller must call [RECORDER_CONFIGURE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-recorder_configure_params_init).