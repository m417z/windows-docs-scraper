# IPerChannelDbLevel::SetLevelAllChannels

## Description

The **SetLevelAllChannels** method sets the volume levels, in decibels, of all the channels in the audio stream.

## Parameters

### `aLevelsDB` [in]

Pointer to an array of volume levels. This parameter points to a caller-allocated **float** array into which the method writes the new volume levels, in decibels, for all the channels. The method writes the level for a particular channel into the array element whose index matches the channel number. If the audio stream contains *n* channels, the channels are numbered 0 to *n*– 1. To get the number of channels in the stream, call the [IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount) method.

### `cChannels` [in]

The number of elements in the *aLevelsDB* array. If this parameter does not match the number of channels in the audio stream, the method fails without modifying the *aLevelsDB* array.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetLevelAllChannels** call changes the state of the level control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *cChannels* does not equal the number of channels. |
| **E_POINTER** | Pointer *aLevelsDB* is **NULL**. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

If the specified level value for any channel is beyond the range that the [IPerChannelDbLevel::GetLevelRange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevelrange) method reports for that channel, the **SetLevelAllChannels** call clamps the value to the supported range and completes successfully. A subsequent call to the [IPerChannelDbLevel::GetLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevel) method retrieves the actual value used for that channel.

## See also

[IPerChannelDbLevel Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iperchanneldblevel)

[IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount)

[IPerChannelDbLevel::GetLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevel)

[IPerChannelDbLevel::GetLevelRange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevelrange)