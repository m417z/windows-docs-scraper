## Description

The **ACX_COMPOSITE_TEMPLATE_CONFIG** structure is used to configure a new ACX composite template object.

## Members

### `Size`

The size of all of the data in the **ACX_COMPOSITE_TEMPLATE_CONFIG** structure in bytes. This field is set by the [ACX_COMPOSITE_TEMPLATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acx_composite_template_config_init) function.

### `Flags`

A combination of values from the [ACX_COMPOSITE_TEMPLATE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/ne-acxmanager-acx_composite_template_config_flags) enum that describe the composite template.

### `Properties`

An optional **ACXOBJECTBAG** of composite template properties. Only for singleton composites.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_COMPOSITE_TEMPLATE_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/nf-acxmanager-acx_composite_template_config_init)
- [ACX_COMPOSITE_TEMPLATE_CONFIG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/ne-acxmanager-acx_composite_template_config_flags)
- [acxmanager.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmanager/)