# IAudioChannelConfig::SetChannelConfig

## Description

The **SetChannelConfig** method sets the channel-configuration mask in a channel-configuration control.

## Parameters

### `dwConfig` [in]

The channel-configuration mask.

### `pguidEventContext` [in]

Context value for the [IControlChangeNotify::OnNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-icontrolchangenotify-onnotify) method. This parameter points to an event-context GUID. If the **SetChannelConfig** call changes the state of the channel-configuration control, all clients that have registered [IControlChangeNotify](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-icontrolchangenotify) interfaces with that control receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the control-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

For information about channel-configuration masks, see the discussion of the [KSPROPERTY_AUDIO_CHANNEL_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-channel-config) property in the Windows DDK documentation.

## See also

[IAudioChannelConfig Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig)

[IAudioChannelConfig::GetChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiochannelconfig-getchannelconfig)