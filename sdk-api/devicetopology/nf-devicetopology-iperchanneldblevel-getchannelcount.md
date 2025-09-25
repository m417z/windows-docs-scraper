# IPerChannelDbLevel::GetChannelCount

## Description

The **GetChannelCount** method gets the number of channels in the audio stream.

## Parameters

### `pcChannels` [out]

Pointer to a **UINT** variable into which the method writes the channel count (the number of channels in the audio stream).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pcChannels* is **NULL**. |

## See also

[IPerChannelDbLevel Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iperchanneldblevel)