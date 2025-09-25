# IOfflineFilesErrorInfo::GetDescription

## Description

Retrieves a text string describing the error. In most cases, this is the system error string reported for the sync result using the Win32 function [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage).

## Parameters

### `ppszDescription` [out]

Receives the address of a text string describing the error. The caller must free this memory block by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## See also

[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage)

[IOfflineFilesErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefileserrorinfo)