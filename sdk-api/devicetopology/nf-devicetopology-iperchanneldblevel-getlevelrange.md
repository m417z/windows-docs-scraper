# IPerChannelDbLevel::GetLevelRange

## Description

The **GetLevelRange** method gets the range, in decibels, of the volume level of the specified channel.

## Parameters

### `nChannel` [in]

The number of the selected channel. If the audio stream has *n* channels, the channels are numbered from 0 to *n*– 1. To get the number of channels in the stream, call the [IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount) method.

### `pfMinLevelDB` [out]

Pointer to a **float** variable into which the method writes the minimum volume level in decibels.

### `pfMaxLevelDB` [out]

Pointer to a **float** variable into which the method writes the maximum volume level in decibels.

### `pfStepping` [out]

Pointer to a **float** variable into which the method writes the stepping value between consecutive volume levels in the range **pfMinLevelDB* to **pfMaxLevelDB*. If the difference between the maximum and minimum volume levels is *d* decibels, and the range is divided into *n* steps (uniformly sized intervals), then the volume can have *n* + 1 discrete levels and the size of the step between consecutive levels is *d* / *n* decibels.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is out of range. |
| **E_POINTER** | Pointer *pfminLevelDB*, *pfmaxLevelDB*, or *pfmaxLevelDB* is **NULL**. |

## See also

[IPerChannelDbLevel Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iperchanneldblevel)

[IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount)