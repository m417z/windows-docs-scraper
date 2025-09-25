# IBackgroundCopyError::GetFile

## Description

Retrieves an interface pointer to the file object associated with the error.

## Parameters

### `pVal` [out]

An [IBackgroundCopyFile](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyfile) interface pointer whose methods you use to determine the local and remote file names associated with the error. The *ppFile* parameter is set to **NULL** if the error is not associated with the local or remote file. When done, release *ppFile*.

## Return value

This method returns the following **HRESULT** values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved an interface pointer to the file object. |
| **BG_E_FILE_NOT_AVAILABLE** | The error is not associated with a local or remote file. The *ppFile* parameter is set to **NULL**. |

## See also

[IBackgroundCopyError::GetError](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterror)

[IBackgroundCopyError::GetErrorContextDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrorcontextdescription)

[IBackgroundCopyError::GetErrorDescription](https://learn.microsoft.com/windows/desktop/api/bits/nf-bits-ibackgroundcopyerror-geterrordescription)