# IMFASFStreamSelector::GetBandwidthStep

## Description

Retrieves the stream numbers that apply to a bandwidth step. This method is used for multiple bit rate (MBR) content.

## Parameters

### `dwStepNum` [in]

Bandwidth step number for which to retrieve information. Set this value to a number between 0, and 1 less than the number of bandwidth steps returned by [IMFASFStreamSelector::GetBandwidthStepCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getbandwidthstepcount).

### `pdwBitrate` [out]

Receives the bit rate associated with the bandwidth step.

### `rgwStreamNumbers` [out]

Address of an array that receives the stream numbers. The caller allocates the array. The array size must be at least as large as the value returned by the [IMFASFStreamSelector::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getstreamcount) method.

### `rgSelections` [out]

Address of an array that receives the selection status of each stream, as an [ASF_SELECTION_STATUS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-asf_selection_status) value. The members of this array correspond to the members of the *rgwStreamNumbers* array by index. The caller allocates the array. The array size must be at least as large as the value returned by the [IMFASFStreamSelector::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getstreamcount) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Bandwidth steps are bandwidth levels used for MBR content. If you stream MBR content, you can choose the bandwidth step that matches the network conditions to avoid interruptions during playback.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)

[IMFASFStreamSelector::GetBandwidthStepCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getbandwidthstepcount)