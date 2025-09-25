# IPerChannelDbLevel::GetLevel

## Description

The **GetLevel** method gets the volume level, in decibels, of the specified channel.

## Parameters

### `nChannel` [in]

The channel number. If the audio stream has *N* channels, the channels are numbered from 0 to *N*– 1. To get the number of channels in the stream, call the [IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount) method.

### `pfLevelDB` [out]

Pointer to a **float** variable into which the method writes the volume level, in decibels, of the specified channel.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is out of range. |
| **E_POINTER** | Pointer *pfLevelDB* is **NULL**. |

## See also

[IPerChannelDbLevel Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iperchanneldblevel)

[IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount)