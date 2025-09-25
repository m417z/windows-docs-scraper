# WppRecorderConfigure macro

## Description

The [WppRecorderConfigure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderconfigure) method enables or disables the default log to which WPP prints.

## Syntax

```cpp
__drv_maxIRQL(PASSIVE_LEVEL)
VOID WppRecorderConfigure(
    _In_         PRECORDER_CONFIGURE_PARAMS  ConfigureParams
    );
```

## Parameters

### `ConfigureParams`

Pointer to a caller-allocated [**RECORDER_CONFIGURE_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_configure_params) structure.

## Remarks

Before calling [WppRecorderConfigure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderconfigure), allocate a [RECORDER_CONFIGURE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_configure_params) structure and initialize by calling [RECORDER_CONFIGURE_PARAMS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-recorder_configure_params_init).

This method only configures the default log. By default that log is enabled. If you have a custom log, you must disable the default log by setting the **CreateDefaultLog** to FALSE.

#### Example

```cpp
RECORDER_CONFIGURE_PARAMS                recorderConfigure;

RECORDER_CONFIGURE_PARAMS_INIT(&recorderConfigure);
// Optionally use the following line to get timestamps in WPP log entries
recorderConfigure.UseTimeStamp    = WppRecorderTrue;
// Use this line if you would like more precise timestamps (ten millionths of a second). This is valid only if you have set UseTimeStamp = WppRecorderTrue.
// recorderConfigure.PreciseTimeStamp = WppRecorderTrue
status = WppRecorderConfigure(&recorderConfigure);
```

For more info about timestamps in WPP log entries including sample log output, see [Inflight Trace Recorder (IFR) for logging traces](https://learn.microsoft.com/windows-hardware/drivers/devtest/using-wpp-recorder).