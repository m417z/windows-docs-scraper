# IBDA_DRIDRMService::SetDRM

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Selects a Digital Rights Management (DRM) application for a Media Transform Device (MTD) in a Protected Broadcast Device Architecture (PBDA) graph. The MTD sets the DRMPairingStatus value to "Red", which indicates an unpaired state, and switches to the designated DRM application within five seconds.

## Parameters

### `bstrNewDrm` [in]

Address of the GUID that identifies the new DRM application.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_DRIDRMService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_dridrmservice)