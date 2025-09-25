# ConvertPerformanceCounterToAuxiliaryCounter function

## Description

Converts the specified performance counter value to the corresponding auxiliary counter value; optionally provides the estimated conversion error in nanoseconds due to latencies and maximum possible drift.

## Parameters

### `ullPerformanceCounterValue` [in]

The performance counter value to convert.

### `lpAuxiliaryCounterValue` [out]

On success, contains the converted auxiliary counter value. Will be undefined if the function fails.

### `lpConversionError` [out, optional]

On success, contains the estimated conversion error, in nanoseconds. Will be undefined if the function fails.

## Return value

Returns **S_OK** if the conversion succeeds; otherwise, returns another **HRESULT** specifying the error.

| Return value | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_NOTIMPL** | The auxiliary counter is not supported. |
| **E_BOUNDS** | The value to convert is outside the permitted range (+/- 10 seconds from when the called occurred). |
| **E_BOUNDS** | The value to convert is prior to the last system boot or S3/S4 transition. |