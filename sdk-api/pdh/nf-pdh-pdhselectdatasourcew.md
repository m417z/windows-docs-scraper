# PdhSelectDataSourceW function

## Description

Displays a dialog window that prompts the user to specify the source of the performance data.

## Parameters

### `hWndOwner` [in]

Owner of the dialog window. This can be **NULL** if there is no owner (the desktop becomes the owner).

### `dwFlags` [in]

Dialog boxes that will be displayed to prompt for the data source. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PDH_FLAGS_FILE_BROWSER_ONLY** | Display the file browser only. Set this flag when you want to prompt for the name and location of a log file only. |
| **0** | Display the data source selection dialog box. The dialog box lets the user select performance data from either a log file or a real-time source. If the user specified that data is to be collected from a log file, a file browser is displayed for the user to specify the name and location of the log file. |

### `szDataSource` [out]

Caller-allocated buffer that receives a **null**-terminated string that contains the name of a log file that the user selected. The log file name is truncated to the size of the buffer if the buffer is too small.

If the user selected a real time source, the buffer is empty.

### `pcchBufferLength` [in, out]

Maximum size of the *szDataSource* buffer, in **TCHARs**.

## Return value

If the function succeeds, it returns ERROR_SUCCESS.

If the function fails, the return value is a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) or a
[PDH error code](https://learn.microsoft.com/windows/desktop/PerfCtrs/pdh-error-codes). The following are possible values.

| Return code | Description |
| --- | --- |
| **PDH_INVALID_ARGUMENT** | The length of the buffer passed in the *pcchBufferLength* is not equal to the actual length of the *szDataSource* buffer. |
| **PDH_MEMORY_ALLOCATION_FAILURE** | A zero-length buffer was passed in the *szDataSource* parameter. |

## See also

[PdhIsRealTimeQuery](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhisrealtimequery)

## Remarks

> [!NOTE]
> The pdh.h header defines PdhSelectDataSource as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).