# IBDA_DRM::PerformDRMPairing

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **PerformDRMPairing** method requests the tuner to perform a DRM handshake with the user's computer.

## Parameters

### `fSync` [in]

If **TRUE**, the method blocks until the operation is completed. If **FALSE**, the operation is completed asynchronously.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

If you call this method asynchronously (*fSync* equal to **FALSE**), you can poll the status of the operation by calling [IBDA_DRM::GetDRMPairingStatus](https://learn.microsoft.com/windows/desktop/api/bdaiface/nf-bdaiface-ibda_drm-getdrmpairingstatus). While the operation is in progress, **GetDRMPairingStatus** returns S_FALSE.

## See also

[IBDA_DRM Interface](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_drm)