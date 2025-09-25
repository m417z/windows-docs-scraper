# IAudioChannelConfig::GetChannelConfig

## Description

The **GetChannelConfig** method gets the current channel-configuration mask from a channel-configuration control.

## Parameters

### `pdwConfig` [out]

Pointer to a **DWORD** variable into which the method writes the current channel-configuration mask value.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pdwConfig* is **NULL**. |

## Remarks

For information about channel-configuration masks, see the discussion of the [KSPROPERTY_AUDIO_CHANNEL_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-channel-config) property in the Windows DDK documentation.

## See also

[IAudioChannelConfig Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-iaudiochannelconfig)

[IAudioChannelConfig::SetChannelConfig](https://learn.microsoft.com/windows/desktop/api/devicetopology/nf-devicetopology-iaudiochannelconfig-setchannelconfig)