# _PEP_PROCESSOR_PARK_PREFERENCE structure (pep_x.h)

## Description

The **PEP_PROCESSOR_PARK_PREFERENCE** structure indicates the preferences of the operating system and platform extension plug-in (PEP) regarding whether the specified processor should be parked to reduce power consumption.

## Members

### `Processor`

A **PEPHANDLE** value that identifies the processor. The PEP supplied this handle in a previous [PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device) notification.

### `PoPreference`

The operating system's parking preference for this processor. For more information, see Remarks.

### `PepPreference`

The PEP's parking preference for this processor. For more information, see Remarks.

## Remarks

The **Processors** member of the [PEP_PPM_PARK_SELECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_selection) structure is a pointer to an array of **PEP_PROCESSOR_PARK_PREFERENCE** structures.

The **Processor** and **PoPreference** members of the **PEP_PROCESSOR_PARK_PREFERENCE** structure contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) when a [PEP_NOTIFY_PPM_PARK_SELECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_selection) notification is sent to the PEP. The **PepPreference** member contains an output value that the PEP writes to the structure in response to this notification.

The following table lists the three values that are defined for the **PoPreference** and **PepPreference** members.

| Parking preference | Value | Meaning |
| --- | --- | --- |
| PROCESSOR_PARK_PREFERENCE_NONE | 0x0 | No preference. Either parked or unparked is okay. |
| PROCESSOR_PARK_PREFERENCE_PARKED | 0x1 | The operating system or PEP specifies that the processor should be parked. |
| PROCESSOR_PARK_PREFERENCE_UNPARKED | 0x2 | The operating system or PEP specifies that the processor should not be parked. |

## See also

[PEP_DPM_REGISTER_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_register_crashdump_device)

[PEP_NOTIFY_PPM_PARK_SELECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_selection)

[PEP_PPM_PARK_SELECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_selection)