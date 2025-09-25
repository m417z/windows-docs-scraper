# IBDA_DRM::GetDRMPairingStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetDRMPairingStatus** method queries the status of the DRM handshake.

## Parameters

### `pdwStatus` [out]

Receives a value from the [BDA_DrmPairingError](https://learn.microsoft.com/windows/desktop/api/bdaiface/ne-bdaiface-bda_drmpairingerror) enumeration.

### `phError` [out]

Receives an **HRESULT** value indicating the success or failure of the DRM handshake.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The device does not support this functionality, or the handshake is still in progress. |

## See also

[IBDA_DRM Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_drm)