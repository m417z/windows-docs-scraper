# IBackgroundCopyJob2::GetNotifyCmdLine

## Description

Retrieves the program to execute when the job enters the error or transferred state.

## Parameters

### `pProgram` [out]

Null-terminated string that contains the program to execute when the job enters the error or transferred state. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *pProgram* when done.

### `pParameters` [out]

Null-terminated string that contains the arguments of the program in *pProgram*. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *pParameters* when done.

## Return value

This method returns **S_OK** on success or one of the standard COM **HRESULT** values on error.

## Remarks

The
**GetNotifyCmdLine** method sets *pProgram* and *pParameters* to an empty string (L"") if the
[IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline) method has not been called.

## See also

[IBackgroundCopyJob2::SetNotifyCmdLine](https://learn.microsoft.com/windows/desktop/api/bits1_5/nf-bits1_5-ibackgroundcopyjob2-setnotifycmdline)