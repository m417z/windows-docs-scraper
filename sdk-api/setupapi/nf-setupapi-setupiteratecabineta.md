# SetupIterateCabinetA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupIterateCabinet** function iterates through all the files in a cabinet and sends a notification to a callback function for each file found.

## Parameters

### `CabinetFile` [in]

Cabinet (.CAB) file to iterate through.

### `Reserved` [in]

Not currently used.

### `MsgHandler` [in]

Pointer to a [FileCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nc-setupapi-psp_file_callback_a) routine that will process the notifications
**SetupIterateCabinet** returns as it iterates through the files in the cabinet file. The callback routine may then return a value specifying whether to decompress, copy, or skip the file.

### `Context` [in]

Context value that is passed into the routine specified in *MsgHandler*. This enables the callback routine to track values between notifications, without having to use global variables.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupIterateCabinet as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).