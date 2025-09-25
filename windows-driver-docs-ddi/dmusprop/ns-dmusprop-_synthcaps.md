# _SYNTHCAPS structure

## Description

The SYNTHCAPS structure specifies the capabilities of a synthesizer.

## Members

### `Guid`

Specifies the class ID for the synthesizer's miniport driver interface.

### `Flags`

Specifies the general capabilities of the driver. This member is a bitfield whose value is either zero or the bitwise OR of one or more of the following flag bits:

#### SYNTH_PC_DLS

The driver supports downloadable sample collections (DLS Level 1).

#### SYNTH_PC_EXTERNAL

The synth represents a connection to external hardware.

#### SYNTH_PC_SOFTWARESYNTH

The driver implements a software synthesizer.

#### SYNTH_PC_MEMORYSIZEFIXED

The memory size given in the **MemorySize** member is valid and represents the maximum amount of sample memory in bytes. This flag is typically set when the sample memory is not system memory.

#### SYNTH_PC_GMINHARDWARE

The synth supports the General MIDI sound set in hardware.

#### SYNTH_PC_GSINHARDWARE

The synth supports the Roland GS sound set in hardware.

#### SYNTH_PC_REVERB

The synth supports reverb.

#### SYNTH_PC_DLS2

The driver supports downloadable sample collections (DLS Level 2).

#### SYNTH_PC_SYSTEMMEMORY

The synth can use system memory.

### `MemorySize`

Specifies the amount of sample memory on the device (in bytes). This field should contain the value SYNTH_PC_SYSTEMMEMORY if the device uses system memory for sample memory with no limitation on the amount of memory allocated.

### `MaxChannelGroups`

Specifies the maximum number of channel groups this driver supports. Each channel group represents a set of 16 MIDI channels and has associated with it all the state that a MIDI hardware device would keep, which includes DLS, GM, GS, XG, or other mode information. DLS downloads, however, are per-driver and can be used by any of the channel groups. This prevents wasting memory by downloading several copies of the same DLS sample, one per channel group.

### `MaxVoices`

Specifies the maximum number of voices that the rendering device supports. If the property handler is unable to provide a valid number for this member, it should set the member to (ULONG)-1.

### `MaxAudioChannels`

Specifies the maximum number of audio channels that the rendering device supports. If the property handler is unable to provide a valid number for this member, it should set the member to (ULONG)-1.

### `EffectFlags`

Specifies the effects that the rendering device is capable of producing. This member is a bitfield whose value is either zero or the bitwise OR of the following flag bits:

#### SYNTH_EFFECT_REVERB

Rendering device can produce reverb effect.

#### SYNTH_EFFECT_CHORUS

Rendering device can produce chorus effect.

#### SYNTH_EFFECT_DELAY

Rendering device can produce delay effect.

If the device supports none of these capabilities, set this member to SYNTH_EFFECT_NONE (zero).

### `Description`

Contains a text description of the device. This member is a WCHAR array containing a null-terminated string (for example, "Microsoft MPU-401").

## Remarks

The [KSPROPERTY_SYNTH_CAPS](https://learn.microsoft.com/previous-versions/ff537389(v=vs.85)) get-property request uses the SYNTHCAPS structure to retrieve the capabilities of a synthesizer device from a DMus miniport driver.

SYNTH_CAPS is similar to the DMUS_PORTCAPS structure, which is described in the Microsoft Windows SDK documentation.

In the DMusUART sample driver in the Windows Driver Kit (WDK), the KSPROPERTY_SYNTH_CAPS property handler sets the members of the SYNTHCAPS structure to the following values:

```
  SYNTHCAPS *caps = (SYNTHCAPS*)pRequest->Value;
  ...
  caps->Flags              = SYNTH_PC_EXTERNAL;
  caps->MemorySize         = 0;
  caps->MaxChannelGroups   = 1;
  caps->MaxVoices          = 0xFFFFFFFF;  // (ULONG)-1
  caps->MaxAudioChannels   = 0xFFFFFFFF;  // (ULONG)-1
  caps->EffectFlags        = 0;
```

In this example, the 0xFFFFFFFF values indicate that the handler has no way of knowing the actual **MaxVoices** and **MaxAudioChannels** limits because they are completely dependent on whatever external synthesizer happens to be connected to the UART. Elsewhere in the code, but not shown in the preceding example, the DMusUART property handler sets the **Guid** member of the SYNTHCAPS structure to either **CLSID_MiniportDriverDMusUART** or **CLSID_MiniportDriverDMusUARTCapture**. The one the **Guid** member is it is set to depends on whether the target node (of type [KSNODETYPE_SYNTHESIZER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-synthesizer)) for the property request lies on a data path that handles rendering data or capture data. Both class IDs are defined in header file Dmusicks.h.

## See also

[KSNODETYPE_SYNTHESIZER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksnodetype-synthesizer)

[KSPROPERTY_SYNTH_CAPS](https://learn.microsoft.com/previous-versions/ff537389(v=vs.85))