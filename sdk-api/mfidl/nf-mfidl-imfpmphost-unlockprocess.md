# IMFPMPHost::UnlockProcess

## Description

Decrements the lock count on the protected media path (PMP) process. Call this method once for each call to [IMFPMPHost::LockProcess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpmphost-lockprocess).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFPMPHost](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphost)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)