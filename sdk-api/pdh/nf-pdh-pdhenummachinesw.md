# PdhEnumMachinesW function

## Description

Returns a list of the computer names associated with counters in a log file. The computer names were either specified when adding counters to the query or when calling the [PdhConnectMachine](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhconnectmachinea) function. The computers listed include those that are currently connected and online, in addition to those that are offline or not returning performance data.

To use handles to data sources, use the
[PdhEnumMachinesH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenummachinesha) function.

## Parameters

### `szDataSource` [in]

**Null**-terminated string that specifies the name of a log file. The function enumerates the names of the computers whose counter data is in the log file. If **NULL**, the function enumerates the list of computers that were specified when adding counters to a real time query or when calling the [PdhConnectMachine](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhconnectmachinea) function.

### `mszMachineList` [out]

Caller-allocated buffer to receive the list of **null**-terminated strings that contain the computer names. The list is terminated with two **null**-terminator characters. Set to **NULL** if *pcchBufferLength* is zero.

### `pcchBufferSize` [in, out]

Size of the *mszMachineNameList* buffer, in **TCHARs**. If zero on input, the function returns PDH_MORE_DATA and sets this parameter to the required buffer size. If the buffer is larger than the required size, the function sets this parameter to the actual size of the buffer that was used. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_MORE_DATA** | The *mszMachineNameList* buffer is too small to contain all the data. This return value is expected if *pcchBufferLength* is zero on input. If the specified size on input is greater than zero but less than the required size, you should not rely on the returned size to reallocate the buffer. |
| **PDH_INVALID_ARGUMENT** | A parameter is not valid. For example, on some releases you could receive this error if the specified size on input is greater than zero but less than the required size. |

## Remarks

You should call this function twice, the first time to get the required buffer size (set *mszMachineNameList* to **NULL** and *pcchBufferLength* to 0), and the second time to get the data.

> [!NOTE]
> The pdh.h header defines PdhEnumMachines as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PdhConnectMachine](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhconnectmachinea)

[PdhEnumMachinesH](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhenummachinesha)