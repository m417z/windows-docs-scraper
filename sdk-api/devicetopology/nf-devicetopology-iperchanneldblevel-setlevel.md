# IPerChannelDbLevel::SetLevel

## Description

The **SetLevel** method sets the volume level, in decibels, of the specified channel.

## Parameters

### `nChannel` [in]

The number of the selected channel. If the audio stream has *N* channels, the channels are numbered from 0 to *N*– 1. To get the number of channels in the stream, call the [IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount) method.

### `fLevelDB` [in]

The new volume level in decibels. A positive value represents gain, and a negative value represents attenuation.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetLevel** call changes the state of the level control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is out of range. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

If the caller specifies a value for *fLevelDB* that is an exact stepping value, the **SetLevel** method completes successfully. A subsequent call to the [IPerChannelDbLevel::GetLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevel) method will return either the value that was set, or one of the following values:

* If the set value was below the minimum, the **GetLevel** method returns the minimum value.
* If the set value was above the maximum, the **GetLevel** method returns the maximum value.
* If the set value was between two stepping values, the **GetLevel** method returns a value that could be the next stepping value above or the stepping value below the set value; the relative distances from the set value to the neighboring stepping values is unimportant. The value that the **GetLevel** method returns is whichever value has more of an impact on the signal path.

## See also

[IPerChannelDbLevel Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iperchanneldblevel)

[IPerChannelDbLevel::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getchannelcount)

[IPerChannelDbLevel::GetLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevel)

[IPerChannelDbLevel::GetLevelRange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevelrange)