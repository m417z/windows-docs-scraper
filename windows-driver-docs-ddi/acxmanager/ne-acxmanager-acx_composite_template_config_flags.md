## Description

The **ACX_COMPOSITE_TEMPLATE_CONFIG_FLAGS** enumeration is used to configure the properties of a composite template used by the audio class extension (ACX) manager.

## Constants

### `AcxCompositeTemplateConfigNoFlags`

Indicates that there are no flags set.

### `AcxCompositeTemplateConfigPrivate`

For internal use only, do not use.

### `AcxCompositeTemplateConfigSingleton`

Indicates that the composite template represents a composite singleton, so it does not repeat in the system.

### `AcxCompositeTemplateConfigValidFlags`

For internal validation, do not use.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)