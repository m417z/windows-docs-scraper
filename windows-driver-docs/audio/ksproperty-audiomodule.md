# KSPROPERTY\_AUDIOMODULE enumeration

The KSPROPERTY\_AUDIOMODULE enumeration defines constants that are used by audio drivers to communicate information about partner defined audio modules.

For more information about audio modules, see [Implementing Audio Module Discovery](https://learn.microsoft.com/windows-hardware/drivers/audio/implementing-audio-module-communication).

## Constants

**KSPROPERTY\_AUDIOMODULE\_DESCRIPTORS**
Specifies the ID for the [**KSPROPERTY\_AUDIOMODULE\_DESCRIPTORS**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audiomodule-descriptors) property.

**KSPROPERTY\_AUDIOMODULE\_COMMAND**
Specifies the ID for the [**KSPROPERTY\_AUDIOMODULE\_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audiomodule-command) property.

**KSPROPERTY\_AUDIOMODULE\_NOTIFICATION\_DEVICE\_ID**
Specifies the ID for the [**KSPROPERTY\_AUDIOMODULE\_NOTIFICATION\_DEVICE\_ID**](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audiomodule-notification-device-id) property.

## Remarks

All KS Property calls must be non-blocking because the hardware effects are part of the processing chain and should not wait.

## Requirements

|  |  |
| --- | --- |
| Minimum supported client | Windows 10, version 1703 |
| Minimum supported server | None supported |
| Header | Ksmedia.h |

## See also

[KSPROPSETID\_AudioModule](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-audiomodule)

