# IMFPMPServer::UnlockProcess

## Description

Decrements the lock count on the protected media path (PMP) process. Call this method once for each call to [IMFPMPServer::LockProcess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpmpserver-lockprocess).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFPMPServer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmpserver)