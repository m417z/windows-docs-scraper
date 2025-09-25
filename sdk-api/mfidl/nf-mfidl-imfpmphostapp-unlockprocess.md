# IMFPMPHostApp::UnlockProcess

## Description

Decrements the lock count on the protected media path (PMP) process. Call this method once for each call to [IMFPMPHostApp::LockProcess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpmphostapp-lockprocess).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFPMPHostApp](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphostapp)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)