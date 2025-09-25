# KSRTAUDIO_HWREGISTER_PROPERTY structure

## Description

The KSRTAUDIO_HWREGISTRY_PROPERTY structure appends a register base address to a KSPROPERTY structure. This structure is used by the client to request the hardware position register via [KSPROPERTY_RTAUDIO_POSITIONREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-positionregister) or request the hardware clock register via [KSPROPERTY_RTAUDIO_CLOCKREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-clockregister).

## Members

### `Property`

A [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that the client initializes appropriately prior to calling KSPROPERTY_RTAUDIO_POSITIONREGISTER or KSPROPERTY_RTAUDIO_CLOCKREGISTER.

### `BaseAddress`

Specifies the buffer base address. Unless the client specifies a base address, this parameter is set to **NULL**.

## Remarks

The client uses the KSRTAUDIO_HWREGISTER_PROPERTY structure to request the hardware position register or the hardware clock register from the driver. The driver returns a [KSRTAUDIO_HWREGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_hwregister) structure containing information about the requested hardware register.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_RTAUDIO_CLOCKREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-clockregister)

[KSPROPERTY_RTAUDIO_POSITIONREGISTER](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-positionregister)

[KSRTAUDIO_HWREGISTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_hwregister)