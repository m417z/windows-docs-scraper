# IBackgroundCopyError::GetProtocol

## Description

Retrieves the protocol used to transfer the file. The remote file name identifies the protocol to use to transfer the file.

## Parameters

### `pProtocol` [out]

Null-terminated string that contains the protocol used to transfer the file. The string contains "http" for the HTTP protocol and "file" for the SMB protocol. The *ppProtocol* parameter is set to **NULL** if the error is not related to the transfer protocol. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *ppProtocol* when done.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| ****S_OK**** | Successfully retrieved the remote file protocol. |
| **BG_E_PROTOCOL_NOT_AVAILABLE** | The error is not associated with the remote file transfer protocol. The *ppProtocol* parameter is set to **NULL**. |

## See also

[IBackgroundCopyError](https://learn.microsoft.com/windows/desktop/api/bits/nn-bits-ibackgroundcopyerror)