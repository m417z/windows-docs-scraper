# KSRTAUDIO_HWREGISTER structure

## Description

The KSRTAUDIO_HWREGISTER structure specifies the address and additional information about a hardware register requested by the client. It is filled in by the driver in response to a register request via [KSPROPERTY_RTAUDIO_POSITIONREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-positionregister) and [KSPROPERTY_RTAUDIO_CLOCKREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-clockregister).

## Members

### `Register`

Pointer to the register. This member specifies the virtual address into which the register is mapped.

### `Width`

Specifies the width, in bits, of the register. The value of this member can be 32 or 64.

### `Numerator`

Specifies the numerator of the frequency at which the clock register increments. See the following Remarks. section.

### `Denominator`

Specifies the denominator of the frequency at which the clock register increments. See the following Remarks. section.

### `Accuracy`

Specifies the accuracy of the clock or position register. See the following Remarks section.

## Remarks

For hardware position register requests via KSPROPERTY_RTAUDIO_POSITIONREGISTER the driver fills in the **Register**, **Width** and **Accuracy** members, because the other members are specific to clock registers. For hardware clock register requests via KSPROPERTY_RTAUDIO_CLOCKREGISTER the driver fills in the entire structure.

A clock register is a counter that increments at the frequency of the internal hardware clock that drives the internal bus of the audio device. The register increments by one with each tick of the clock. The register begins counting when the device powers on and continues to run until the device powers off. The clock register is used by software to synchronize two or more devices with independent hardware clocks.

Members **Numerator** and **Denominator** together specify the frequency at which the clock register increments. The frequency is calculated by dividing **Numerator** by **Denominator**.

The clock register increments at the frequency of the internal clock of the audio device. This is the frequency that the audio device typically uses to clock events on its internal bus or on the external codec link. The hardware derives the audio sample frequencies by dividing down the internal clock frequency.

The audio device can derive its internal clock from an on-chip crystal oscillator or an external clock signal. For example, if a device derives a 16.5-MHz internal clock by dividing a 33-MHz external clock by two, the numerator and denominator can be specified as 33,000,000 and 2, respectively.

The *Accuracy* parameter specifies the maximum error in a position or clock register reading. This is essentially a representation of the update rate for the register. For clock registers the *Accuracy* parameter indicates the number of clock ticks between register updates. In the preceding example of a 16.5-MHz internal clock, if the clock register is updated every 4 clocks, the *Accuracy* parameter would be set to 4 because the register needs to represent the accuracy of the clock register in units of clock ticks.

For position registers, the *Accuracy* parameter represents the accuracy of the position register in units of bytes. For example, the audio frame size for a 2-channel, 16-bit PCM stream is 4 bytes. If the position register increments (by two times the frame size) once every second tick of the sample clock, the accuracy value is 8 bytes. If the position register increments (by four times the frame size) once every fourth tick of the sample clock, the accuracy value is 16 bytes, and so on.

## See also

[KSPROPERTY_RTAUDIO_CLOCKREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-clockregister)

[KSPROPERTY_RTAUDIO_POSITIONREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-positionregister)

[KSRTAUDIO_HWREGISTER_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_hwregister_property)