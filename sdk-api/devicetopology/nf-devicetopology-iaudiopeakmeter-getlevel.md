# IAudioPeakMeter::GetLevel

## Description

The **GetLevel** method gets the peak level that the peak meter recorded for the specified channel since the peak level for that channel was previously read.

## Parameters

### `nChannel` [in]

The channel number. If the audio stream has *N* channels, the channels are numbered from 0 to *N*– 1. To get the number of channels in the stream, call the [IAudioPeakMeter::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiopeakmeter-getchannelcount) method.

### `pfLevel` [out]

Pointer to a **float** variable into which the method writes the peak meter level in decibels.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is out of range. |
| **E_POINTER** | Pointer *pfLevel* is **NULL**. |

## See also

[IAudioPeakMeter Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiopeakmeter)

[IAudioPeakMeter::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiopeakmeter-getchannelcount)