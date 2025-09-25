# SetupQueryFileLogW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupQueryFileLog** function returns information from a setup file log.

## Parameters

### `FileLogHandle` [in]

Handle to the file log as returned by [SetupInitializeFileLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitializefileloga).

### `LogSectionName` [in]

Optional pointer to the section name for the log file in a format that is meaningful to the caller. You should use a **null**-terminated string. Required for non-system logs. If no *LogSectionName* is specified for a system log, a default is supplied.

### `TargetFilename` [in]

Name of the file for which log information is desired. You should use a **null**-terminated string.

### `DesiredInfo` [in]

Indicates what information should be returned to the *DataOut* buffer. This parameter can be one of the following enumerated values.

| Value | Meaning |
| --- | --- |
| **SetupFileLogSourceFile name** | Name of the source file as it exists on the source media |
| **SetupFileLogChecksum** | A checksum value used by the system log |
| **SetupFileLogDiskTagfile** | Name of the tag file of the media source containing the source file |
| **SetupFileLogDiskDescription** | The human-readable description of the media where the source file resides |
| **SetupFileLogOtherInfo** | Additional information associated with the logged file |

If the value of *DesiredInfo* is greater than **SetupFileLogOtherInfo** the function will fail, and [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INVALID_PARAMETER.

### `DataOut` [in, out]

Optional pointer to a buffer in which this function returns the requested information for the file. You should use a **null**-terminated string. The **null**-terminated string should not exceed the size of the destination buffer. You can call the function once to get the required buffer size, allocate the necessary memory, and then call the function a second time to retrieve the data. See the Remarks section. Using this technique, you can avoid errors due to an insufficient buffer size. Not all information is provided for every file. An error is not returned if an empty entry for the file exists in the log. This parameter can be **NULL**.

### `ReturnBufferSize` [in]

Size of the *DataOut* buffer, in characters. This includes the **null** terminator. If the buffer is too small and *DataOut* is specified, data is not stored in the buffer and the function returns zero. If *DataOut* is not specified, the *ReturnBufferSize* parameter is ignored.

### `RequiredSize` [in, out]

Optional pointer to a variable that receives the required size of *DataOut*, in characters. This number includes the **null** terminator.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If this function is called with a *DataOut* of **NULL** and a *ReturnBufferSize* of zero, the function puts the buffer size needed to hold the specified data into the variable pointed to by *RequiredSize*. If the function succeeds in this, the return value is a nonzero value. Otherwise, the return value is zero and extended error information can be obtained by calling [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the value of *DesiredInfo* is greater than **SetupFileLogOtherInfo** the function will fail, and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INVALID_PARAMETER.

> [!NOTE]
> The setupapi.h header defines SetupQueryFileLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupLogFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuplogfilea)