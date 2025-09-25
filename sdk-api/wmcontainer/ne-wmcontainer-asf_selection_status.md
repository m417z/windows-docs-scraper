# ASF_SELECTION_STATUS enumeration

## Description

Defines the selection options for an ASF stream.

## Constants

### `ASF_STATUS_NOTSELECTED:0`

No samples from the stream are delivered.

### `ASF_STATUS_CLEANPOINTSONLY:1`

Only samples from the stream that are clean points are delivered.

### `ASF_STATUS_ALLDATAUNITS:2`

All samples from the stream are delivered.

## See also

[IMFASFStreamSelector::GetBandwidthStep](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getbandwidthstep)

[IMFASFStreamSelector::GetOutputOverride](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getoutputoverride)

[IMFASFStreamSelector::SetOutputOverride](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-setoutputoverride)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)