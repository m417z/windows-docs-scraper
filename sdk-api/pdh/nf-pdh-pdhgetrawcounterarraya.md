# PdhGetRawCounterArrayA function

## Description

Returns an array of raw values from the specified counter.
Use this function when you want to retrieve the raw counter values of a counter that contains a wildcard character for the instance name.

## Parameters

### `hCounter` [in]

Handle of the counter for whose current raw instance values you want to retrieve. The
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function returns this handle.

### `lpdwBufferSize` [in, out]

Size of the *ItemBuffer* buffer, in bytes. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

### `lpdwItemCount` [out]

Number of raw counter values in the *ItemBuffer* buffer.

### `ItemBuffer` [out]

Caller-allocated buffer that receives the array of
[PDH_RAW_COUNTER_ITEM](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter_item_a) structures; the structures contain the raw instance counter values. Set to **NULL** if *lpdwBufferSize* is zero.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *ItemBuffer* buffer is not large enough to contain the object name. This return value is expected if *lpdwBufferSize* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid or is incorrectly formatted. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |
| **PDH_INVALID_HANDLE** | The counter handle is not valid. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *ItemBuffer* to **NULL** and *lpdwBufferSize* to 0), and the second time to get the data.

The data for the counter is locked for the duration of the call to
**PdhGetRawCounterArray** to prevent any changes during processing of the call.

> [!NOTE]
> The pdh.h header defines PdhGetRawCounterArray as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PDH_RAW_COUNTER_ITEM](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter_item_a)

[PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue)

[PdhGetFormattedCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcounterarraya)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)