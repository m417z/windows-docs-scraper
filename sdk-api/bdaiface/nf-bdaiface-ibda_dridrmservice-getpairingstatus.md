# IBDA_DRIDRMService::GetPairingStatus

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetPairingStatus** method gets the Digital Rights Management (DRM) pairing status for a Media Transform Device (MTD) in a graph under the Protected Broadcast Driver Architecture (PBDA). This status indicates whether a secure pairing exists between the MTD and a Media Sink Device (MSD) so that controlled-access (CA) content can be released.

## Parameters

### `penumPairingStatus` [in, out]

Address of a variable that gets the pairing device status. The caller passes in a pointer to this variable, and this method returns the correct status value in this parameter. The pairing status that is passed back can be any of the following values:

| Value | Meaning |
| --- | --- |
| **"Green"** | The MTD is paired with an MSD, so CA content is released under DRM protection. |
| **"Orange"** | The MTD is paired with an MSD, but this pairing is about to time out. The MSD is expected to refresh its pairing in the background. CA content is released under DRM protection. |
| **"Red"** | The MTD is not paired with an MSD, so CA content is is not released. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IBDA_DRIDRMService](https://learn.microsoft.com/windows/desktop/api/bdaiface/nn-bdaiface-ibda_dridrmservice)