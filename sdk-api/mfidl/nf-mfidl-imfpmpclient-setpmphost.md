# IMFPMPClient::SetPMPHost

## Description

Provides a pointer to the [IMFPMPHost](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphost) interface.

## Parameters

### `pPMPHost` [in]

A pointer to the [IMFPMPHost](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphost) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IMFPMPHost](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphost) pointer is apartment threaded. The media source must add the pointer to the global interface table (GIT) before using it.

## See also

[IMFPMPClient](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmpclient)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)