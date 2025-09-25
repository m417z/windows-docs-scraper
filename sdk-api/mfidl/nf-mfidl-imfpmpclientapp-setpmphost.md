# IMFPMPClientApp::SetPMPHost

## Description

Sets a pointer to the [IMFPMPHostApp](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphostapp) interface allowing a media source to create objects in the PMP process.

## Parameters

### `pPMPHost` [in]

A pointer to the [IMFPMPHostApp](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphostapp) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFPMPClientApp](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmpclientapp)

[Media Foundation Interfaces](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-interfaces)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)