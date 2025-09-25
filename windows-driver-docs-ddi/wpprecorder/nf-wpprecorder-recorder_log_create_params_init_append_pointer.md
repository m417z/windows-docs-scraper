# RECORDER_LOG_CREATE_PARAMS_INIT_APPEND_POINTER function

## Description

The **RECORDER_LOG_CREATE_PARAMS_INIT_APPEND_POINTER** method initializes the [RECORDER_LOG_CREATE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_log_create_params) with the pointer to link logs.

## Parameters

### `Params` [out]

A pointer to a [RECORDER_LOG_CREATE_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_recorder_log_create_params) structure.

### `LogIdentifier` [in, optional]

String identifier for the log.

### `LogIdentifierAppendPointer` [in]

A pointer from each debug message to its IFR’s metadata structure.