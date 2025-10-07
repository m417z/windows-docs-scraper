# KSJACK\_DESCRIPTION3 structure

In version 22H2 and later Windows operating systems, the `KSJACK_DESCRIPTION3` structure can be used to specify and change the current configuration of the jack.

## Members

**ConfigId**

Driver defined bitmask or enum describing the current configuration, changing this value causes
audioendpointbuilder to refresh the cache to ensure that the published endpoint matches the current config.

## Remarks

### Using KSJACK\_DESCRIPTION3 to communicate audio device changes

The Windows audio system caches audio device capabilities during audio endpoint creation. These cached values are for capabilities such as the presence of a HW audio engine, format support, container ID, buffer size characteristics, etc. These cached values are retained for the life of the windows installation. They are refreshed only when the audio driver is updated or during an OS upgrade.

With **KSJACK\_DESCRIPTION3**, the Windows audio system provides a mechanism for the audio driver to request all cached values be discarded and refreshed. The request can be triggered by changes in the audio device capabilities such as resource constraints.

Whenever the driver changes the contents of **KSJACK\_DESCRIPTION3** at runtime, the driver will trigger the existing [KSEVENT_PINCAPS_JACKINFOCHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-description3) event.

The Windows audio system maintains the last reported *ConfigId* value cached on the audio endpoint. The *ConfigId* value is retrieved in response to [KSEVENT_PINCAPS_JACKINFOCHANGE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-description3) event and during normal processing of the audio endpoint at system boot, Audio Endpoint Builder service restart, audio driver update, or interface state changes for the endpoint.

If the retrieved *ConfigId* value differs from the previously stored value, the Windows audio system will discard all previously cached endpoint capabilities and refresh them.

The recommended usage is to define multiple audio endpoint configurations within the driver that is controlled by the *ConfigId* (bitmask or enum) value. For example, *ConfigId* of 1 may indicate the presence of an audio engine node, whereas *ConfigId* 2 would not report an audio engine node. The *ConfigId* in use by the driver is shared with the Windows audio system through [**KSPROPERTY_JACK_DESCRIPTION3**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-description3) and acts to synchronize the endpoint with the capabilities cached by the Windows audio system.

The value of the *ConfigId* is opaque to Windows. The audio driver could use a timestamp or incrementing value chosen at run time in place of a bitmask or enum as suggested above. This strategy is not recommended as it may result in unnecessary endpoint refreshes during boot up or interface changes to synchronize the last stored *ConfigId* value to the newly reported value, even when the endpoint capabilities are unchanged. This approach may also increase the chances of the driver and Windows becoming out of sync, which can result in audio playback failures.

The mechanism used to refresh the cached values on the endpoint when the *ConfigId* changes is the same as used for Operating System Upgrades and Driver Updates. A new endpoint with a different ID is created which will contain the refreshed cached values that match the new *ConfigId* settings for the endpoint, user settings are then copied from the old endpoint to the new endpoint, and finally the old endpoint is deleted. For more information, on the audio endpoint migration process in OS upgrades, see [Operating System Upgrades](https://learn.microsoft.com/windows-hardware/drivers/audio/operating-system-upgrades).

## Requirements

|  |  |
| --- | --- |
| Version | Available in version 22H2 and later Windows operating systems. |
| Header | Ksmedia.h (include Ksmedia.h) |

## See also

[**KSJACK\_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksjack-description)

[**KSPROPERTY_JACK_DESCRIPTION3**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-jack-description3)

[**IKsJackDescription2::GetJackDescription2**](https://learn.microsoft.com/windows/win32/api/devicetopology/nf-devicetopology-iksjackdescription2-getjackdescription2)

[Dynamic Format Change](https://learn.microsoft.com/windows-hardware/drivers/audio/dynamic-format-change)

[Operating System Upgrades](https://learn.microsoft.com/windows-hardware/drivers/audio/operating-system-upgrades)