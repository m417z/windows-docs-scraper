## Description

Specifies the subtype of the color profile.

## Constants

### `CPST_PERCEPTUAL`

A perceptual rendering intent for gamut map model profiles (GMMPs) defined in WCS.

### `CPST_RELATIVE_COLORIMETRIC`

A relative colorimetric rendering intent for GMMPs defined in WCS.

### `CPST_SATURATION`

A saturation rendering intent for GMMPs defined in WCS.

### `CPST_ABSOLUTE_COLORIMETRIC`

An absolute colorimetric rendering intent for GMMPs defined in WCS.

### `CPST_NONE`

The color profile subtype is not applicable to the selected color profile type.

### `CPST_RGB_WORKING_SPACE`

The RGB color working space for International Color Consortium (ICC) profiles or device model profiles (DMPs) defined in WCS.

### `CPST_CUSTOM_WORKING_SPACE`

A custom color working space.

### `CPST_STANDARD_DISPLAY_COLOR_MODE`

TBD

### `CPST_EXTENDED_DISPLAY_COLOR_MODE`

TBD

## Remarks

For a description of rendering intents, see [Rendering Intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

The PCOLORPROFILESUBTYPE and LPCOLORPROFILESUBTYPE data types are defined as pointers to the **COLORPROFILESUBTYPE** enumeration:

`typedef COLORPROFILESUBTYPE *PCOLORPROFILESUBTYPE, *LPCOLORPROFILESUBTYPE;`

The valid profile type/subtype combinations are

${ROWSPAN3}$ COLORPROFILETYPE\
 ${REMOVE}$

Valid COLORPROFILESUBTYPE\

${ROWSPAN3}$ Notes\
 ${REMOVE}$

default for a device\

global default\

Intended Usage\

Intended Usage\

CPT\_ICC\

CPST\_NONE\

Get/Set default ICC profile associated with a device\

CPST\_RGBWorkingSpace or CPST\_CustomWorkingSpace\

Get/Set ICC profile as global RGB or custom working space\

CPT\_DMP\

CPST\_NONE\

Get/Set default DMP profile associated with a device\

CPST\_RGBWorkingSpace or CPST\_CustomWorkingSpace\

Get/Set DMP as global RGB or custom working space\

CPT\_CAMP\

CPST\_NONE\

Get/Set default CAMP profile associated with a device\

CPST\_NONE\

Get/Set CAMP profile as global color appearance profile\

CPT\_GMMP\

CPST\_NONE\

Get/Set default GMMP profile associated with a device\

CPST\_Perceptual or\
 CPST\_Absolute\_colorimetric or\
 CPST\_Relative\_colorimetric or\
 CPTS\_Saturation\

Get/Set GMMP as global gamut map model profile for a specific rendering intent as described by that subtype to be used in CreateMultiProfileTransform API when resolving the rendering intent array in WCS transform.\

COLORPROFILESUBTYPE Global default can be or?d with WCS\_DEFAULT to set this GMMP as the global default for use in OpenColorProfile or WcsOpenColorProfile where GMMP is **NULL**.\

## See also

* [**COLORPROFILETYPE**](https://learn.microsoft.com/windows/win32/api/icm/ne-icm-colorprofiletype)
* [**WcsSetDefaultColorProfile**](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-wcssetdefaultcolorprofile)