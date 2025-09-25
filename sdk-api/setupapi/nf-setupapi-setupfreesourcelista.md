# SetupFreeSourceListA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupFreeSourceList** function frees the system resources allocated to a source list.

## Parameters

### `List` [in, out]

Pointer to an array of sources from
[SetupQuerySourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupquerysourcelista). The **null**-terminated string should not exceed the size of the destination buffer. When the function returns, this pointer is set to **NULL**.

### `Count` [in]

Number of sources in the list.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCancelTemporarySourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcanceltemporarysourcelist)

[SetupSetSourceList](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupsetsourcelista)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupFreeSourceList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).