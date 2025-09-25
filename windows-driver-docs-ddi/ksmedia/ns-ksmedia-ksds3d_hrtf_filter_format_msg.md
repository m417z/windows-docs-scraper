# KSDS3D_HRTF_FILTER_FORMAT_MSG structure

## Description

The KSDS3D_HRTF_FILTER_FORMAT_MSG structure specifies the filter format to use for a head-relative transfer function (HRTF).

## Members

### `FilterMethod`

Specifies the filter method to use. Set this parameter to one of the following KSDS3D_HRTF_FILTER_METHOD enumeration values:

* DIRECT_FORM
* CASCADE_FORM

For more information, see the description of the **MaxFilterSize** member of [KSDS3D_HRTF_INIT_MSG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksds3d_hrtf_init_msg).

### `CoeffFormat`

Specifies the coefficient format to use. Set this parameter to one of the following KSDS3D_HRTF_COEFF_FORMAT enumeration values:

* FLOAT_COEFF specifies floating-point coefficients.
* SHORT_COEFF specifies 16-bit integer coefficients.

### `Version`

Specifies the filter version. Set this parameter to the KSDS3D_HRTF_FILTER_VERSION enumeration value DS3D_HRTF_VERSION_1.

### `Reserved`

Reserved. Set to zero.

## Remarks

This structure is used by the [KSPROPERTY_HRTF3D_FILTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-hrtf3d-filter-format) property.

For more information, see [KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d).

## See also

[KSPROPERTY_HRTF3D_FILTER_FORMAT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-hrtf3d-filter-format)

[KSPROPSETID_Hrtf3d](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-hrtf3d)