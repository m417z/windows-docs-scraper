# IMFPMPServer::LockProcess

## Description

Blocks the protected media path (PMP) process from ending.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When this method is called, it increments the lock count on the PMP process. For every call to this method, the application should make a corresponding call to [IMFPMPServer::UnlockProcess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpmpserver-unlockprocess), which decrements the lock count. When the PMP process is ready to exit, it waits for about 3 seconds, or until the lock count reaches zero, before exiting.

## See also

[IMFPMPServer](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmpserver)