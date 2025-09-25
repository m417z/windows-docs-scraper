# DIRECTMANIPULATION_CONFIGURATION enumeration

## Description

Defines the interaction configuration states available in [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal).

## Constants

### `DIRECTMANIPULATION_CONFIGURATION_NONE:0`

No interaction is defined.

### `DIRECTMANIPULATION_CONFIGURATION_INTERACTION:0x1`

An interaction is defined. To enable interactions, this value must be included.

Required when setting a configuration other than **DIRECTMANIPULATION_CONFIGURATION_NONE**.

### `DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_X:0x2`

Translation in the horizontal axis.

### `DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_Y:0x4`

Translation in the vertical axis.

### `DIRECTMANIPULATION_CONFIGURATION_SCALING:0x10`

Zoom.

### `DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_INERTIA:0x20`

Inertia for translation as defined by **DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_X** and **DIRECTMANIPULATION_CONFIGURATION_TRANSLATION_Y**.

### `DIRECTMANIPULATION_CONFIGURATION_SCALING_INERTIA:0x80`

Inertia for zoom as defined by **DIRECTMANIPULATION_CONFIGURATION _SCALING**.

### `DIRECTMANIPULATION_CONFIGURATION_RAILS_X:0x100`

Rails on the horizontal axis.

### `DIRECTMANIPULATION_CONFIGURATION_RAILS_Y:0x200`

Rails on the vertical axis.

## See also

[ActivateConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-activateconfiguration)

[AddConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-addconfiguration)

[Direct Manipulation Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-enumerations)

[RemoveConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-removeconfiguration)