# _PEP_PPM_PARK_SELECTION structure (pepfx.h)

## Description

The **PEP_PPM_PARK_SELECTION** structure indicates the preferences of the operating system and platform extension plug-in (PEP) regarding which processors in the platform should be parked to reduce power consumption.

## Members

### `AdditionalUnparkedProcessors` [in]

The number of additional processors that need to be parked.

This number includes all processors in the **Processors** array for which the PEP sets **PepPreference** to PROCESSOR_PARK_PREFERENCE_PARKED but the operating system sets **PoPreference** to either PROCESSOR_PARK_PREFERENCE_UNPARKED or PROCESSOR_PARK_PREFERENCE_NONE. For more information about these values, see [PEP_PROCESSOR_PARK_PREFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_park_preference).

This number does not include processors in the **Processors** array for which the operating system sets the **PoPreference** value to PROCESSOR_PARK_PREFERENCE_PARKED.

### `Count` [in]

The number of elements in the array pointed to by the **Processors** member.

### `Processors` [in/out]

A pointer to an array of [PEP_PROCESSOR_PARK_PREFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_park_preference) structures. The **Count** member specifies the number of elements in the array.

#### On input

Each array element indicates the parking preferences for a particular processor.

#### On output

Returns the PEP parking preference for each processor.

The Processors array is guaranteed to contain the processors in increasing order by processor index.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_PARK_SELECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_selection) notification. All three members of the structure contain input values that are set by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx) before this notification is sent to the PEP.

## See also

[PEP_NOTIFY_PPM_PARK_SELECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_park_selection)

[PEP_PROCESSOR_PARK_PREFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_processor_park_preference)