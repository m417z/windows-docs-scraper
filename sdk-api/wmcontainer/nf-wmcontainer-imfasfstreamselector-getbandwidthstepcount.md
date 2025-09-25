# IMFASFStreamSelector::GetBandwidthStepCount

## Description

Retrieves the number of bandwidth steps that exist for the content. This method is used for multiple bit rate (MBR) content.

## Parameters

### `pcStepCount` [out]

Receives the number of bandwidth steps.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Bandwidth steps are bandwidth levels used for multiple bit rate (MBR) content. If you stream MBR content, you can choose the bandwidth step that matches the network conditions to avoid interruptions during playback.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)

[IMFASFStreamSelector::GetBandwidthStep](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getbandwidthstep)