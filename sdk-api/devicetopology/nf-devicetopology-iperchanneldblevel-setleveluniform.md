# IPerChannelDbLevel::SetLevelUniform

## Description

The **SetLevelUniform** method sets all channels in the audio stream to the same uniform volume level, in decibels.

## Parameters

### `fLevelDB` [in]

The new uniform level in decibels.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetLevelUniform** call changes the state of the level control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

If the specified uniform level is beyond the range that the [IPerChannelDbLevel::GetLevelRange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevelrange) method reports for a particular channel, the **SetLevelUniform** call clamps the value for that channel to the supported range and completes successfully. A subsequent call to the [IPerChannelDbLevel::GetLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevel) method retrieves the actual value used for that channel.

## See also

[IPerChannelDbLevel Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iperchanneldblevel)

[IPerChannelDbLevel::GetLevel](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevel)

[IPerChannelDbLevel::GetLevelRange](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iperchanneldblevel-getlevelrange)