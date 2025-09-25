# IBDA_DRMService::SetDRM

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Activates a digital rights management (DRM) system on the media transform device (MTD).

## Parameters

### `puuidNewDrm` [in]

Pointer to a GUID that specifies the DRM system.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_DRMService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_drmservice)