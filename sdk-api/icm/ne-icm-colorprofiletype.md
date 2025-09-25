## Description

Specifies the type of color profile.

## Constants

### `CPT_ICC`

An International Color Consortium (ICC) profile. If you specify this value, only the CPST\_RGB\_WORKING\_SPACE and CPST\_CUSTOM\_WORKING\_SPACE values of [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) are valid.

### `CPT_DMP`

A device model profile (DMP) defined in WCS. If you specify this value, only the CPST\_RGB\_WORKING\_SPACE and CPST\_CUSTOM\_WORKING\_SPACE values of [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) are valid.

### `CPT_CAMP`

A color appearance model profile (CAMP) defined in WCS. If you specify this value, only the CPST\_NONE value of [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) is valid.

### `CPT_GMMP`

Specifies a WCS gamut map model profile (GMMP). If this value is specified, only the CPST\_PERCEPTUAL, CPST\_SATURATION, CPST\_RELATIVE\_COLORIMETRIC, and CPST\_ABSOLUTE\_COLORIMETRIC values of [**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype) are valid. Any of these values may optionally be combined (in a bitwise **OR** operation) with CPST\_DEFAULT.

## Remarks

The PCOLORPROFILETYPE and LPCOLORPROFILETYPE data types are defined as pointers to this enumeration:

`typedef COLORPROFILETYPE *PCOLORPROFILETYPE, *LPCOLORPROFILETYPE;`

## See also

[**COLORPROFILESUBTYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofilesubtype)