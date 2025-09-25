# IMiniportStreamAudioEngineNode::SetStreamLoopbackProtection

## Description

Sets the loopback protection status of the audio engine node.

## Parameters

### `ProtectionOption` [in]

A CONSTRICTOR_OPTION enumeration value that indicates status of the loopback protection option.

## Return value

**SetStreamLoopbackProtection** returns S_OK, if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

For more information about audio stream loopback protection, see [KSPROPERTY_AUDIOENGINE_LOOPBACK_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-loopback-protection).

## See also

CONSTRICTOR_OPTION

[IMiniportStreamAudioEngineNode](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportstreamaudioenginenode)

[KSPROPERTY_AUDIOENGINE_LOOPBACK_PROTECTION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audioengine-loopback-protection)