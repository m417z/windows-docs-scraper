# IMFPMPHost::LockProcess

## Description

Blocks the protected media path (PMP) process from ending.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When this method is called, it increments the lock count on the PMP process. For every call to this method, the application should make a corresponding call to [IMFPMPHost::UnlockProcess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpmphost-unlockprocess), which decrements the lock count. When the PMP process is ready to exit, it waits for about 3 seconds, or until the lock count reaches zero, before exiting.

## See also

[IMFPMPHost](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphost)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)