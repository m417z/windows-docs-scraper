# IMFASFStreamSelector::BitrateToStepNumber

## Description

Retrieves the index of a bandwidth step that is appropriate for a specified bit rate. This method is used for multiple bit rate (MBR) content.

## Parameters

### `dwBitrate` [in]

The bit rate to find a bandwidth step for.

### `pdwStepNum` [out]

Receives the step number. Use this number to retrieve information about the step by calling [IMFASFStreamSelector::GetBandwidthStep](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getbandwidthstep).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

In a streaming multiple bit rate (MBR) scenario, call this method with the current data rate of the network connection to determine the correct step to use. You can also call this method periodically throughout streaming to ensure that the best step is used.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)