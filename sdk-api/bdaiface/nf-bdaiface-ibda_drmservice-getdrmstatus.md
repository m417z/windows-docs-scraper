# IBDA_DRMService::GetDRMStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the current digital rights management (DRM) status.

## Parameters

### `pbstrDrmUuidList` [out]

Receives a comma-separated list of GUIDs that identify the DRM systems supported by the media transform device (MTD). Each GUID is represented in following format: "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx". The caller must release the string by calling **SysFreeString**.

### `DrmUuid` [out]

Receives a GUID that identifies which DRM system is currently active.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_DRMService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_drmservice)