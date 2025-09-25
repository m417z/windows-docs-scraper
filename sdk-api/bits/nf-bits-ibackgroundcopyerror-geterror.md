# IBackgroundCopyError::GetError

## Description

Retrieves the error code and identify the context in which the error occurred.

## Parameters

### `pContext` [out]

Context in which the error occurred. For a list of context values, see the
[BG_ERROR_CONTEXT](https://learn.microsoft.com/windows/win32/api/bits/ne-bits-bg_error_context) enumeration.

### `pCode` [out]

Error code of the error that occurred.

## Return value

This method returns **S_OK** on success or one of the standard COM HRESULT values on error.

## See also

[IBackgroundCopyError::GetErrorContextDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrorcontextdescription)

[IBackgroundCopyError::GetErrorDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrordescription)

[IBackgroundCopyError::GetFile](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-getfile)