# WppRecorderLogCreate macro

## Description

The **WppRecorderLogCreate** method creates a buffer to contain the recorder log.

## Syntax

```cpp
__drv_maxIRQL(DISPATCH_LEVEL)
NTSTATUS WppRecorderLogCreate(
    [In]        PRECORDER_LOG_CREATE_PARAMS CreateParams,
    [Out]       RECORDER_LOG *              RecorderLog
    );
```

## Parameters

### `CreateParams` [in]

A pointer to a [**RECORDER_LOG_CREATE_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_log_create_params) structure.

### `RecorderLog` [out]

A handle for the recorder log.

## Remarks

Returns NTSTATUS that indicates if the driver can use the *RecorderLog* handle for logging.

Before calling **WppRecorderLogCreate**, allocate a [**RECORDER_LOG_CREATE_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_log_create_params) structure and initialize by calling [RECORDER_LOG_CREATE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-recorder_log_create_params_init).

You must first call [WPP_INIT_TRACING](https://learn.microsoft.com/previous-versions/windows/hardware/previsioning-framework/ff556191(v=vs.85)) before calling **WppRecorderLogCreate**. Default values are used unless the members of *CreateParams* are modified before calling **WppRecorderLogCreate**.

If a successful NTSTATUS is returned, the driver can use the *RecorderLog* handle for logging.

If a successful NTSTATUS is not returned, the driver must use a **RECORDER_LOG** handle to the default log. Also, the driver must not attempt to log to or delete the handle pointed to by *RecorderLog*.

>[!NOTE]
>This method allocates memory for the log buffer from the non-paged pool.

#### Example

```cpp
RECORDER_LOG_CREATE_PARAMS  recorderCreate;
RECORDER_LOG                logHandle;

RECORDER_LOG_CREATE_PARAMS_INIT(&recorderCreate, "Log #1");
recorderCreate.TotalBufferSize = 1024 * 8;
// Optionally use the following line to get timestamps in WPP log entries
recorderCreate.UseTimeStamp    = WppRecorderTrue;
// Use this line if you would like more precise timestamps (ten millionths of a second). This is valid only if you have set UseTimeStamp = WppRecorderTrue.
// recorderCreate.PreciseTimeStamp = WppRecorderTrue
status = WppRecorderLogCreate(&recorderCreate, &logHandle);
```

For more info about timestamps in WPP log entries including sample log output, see [Inflight Trace Recorder (IFR) for logging traces](https://learn.microsoft.com/windows-hardware/drivers/devtest/using-wpp-recorder).

## See also

[**RECORDER_LOG_CREATE_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_log_create_params) structure