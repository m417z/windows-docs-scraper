## Description

Contains information that defines the profile enumeration constraints.

## Members

### `dwSize`

The size of this structure in bytes.

### `dwVersion`

The version number of the **ENUMTYPE** structure. Should be set to ENUM\_TYPE\_VERSION.

### `dwFields`

Indicates which fields in this structure are being used. Can be set to any combination of the following constant values.

ET\_DEVICENAME

ET\_MEDIATYPE

ET\_DITHERMODE

ET\_RESOLUTION

ET\_CMMTYPE

ET\_CLASS

ET\_DATACOLORSPACE

ET\_CONNECTIONSPACE

ET\_SIGNATURE

ET\_PLATFORM

ET\_PROFILEFLAGS

ET\_MANUFACTURER

ET\_MODEL

ET\_ATTRIBUTES

ET\_RENDERINGINTENT

ET\_CREATOR

ET\_DEVICECLASS

### `pDeviceName`

User friendly name of the device.

### `dwMediaType`

Indicates which type of media is associated with the profile, such as a printer or screen.

### `dwDitheringMode`

Indicates the style of dithering that will be used when an image is displayed.

### `dwResolution`

The horizontal (x) and vertical (y) resolution in pixels of the device on which the image will be displayed. The x resolution is stored in **dwResolution\[0\]**, and the y resolution is kept in **dwResolution\[1\]**.

### `dwCMMType`

The identification number of the CMM that is used in the profile. Identification numbers are registered with the ICC.

### `dwClass`

Indicates the profile class. For a description of profile classes, see [Using Device Profiles with WCS](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs). A profile class may have any of the following values.

| Profile Class | Signature |
|--------------------------------|-------------------|
| Input Device Profile | CLASS\_SCANNER |
| Display Device Profile | CLASS\_MONITOR |
| Output Device Profile | CLASS\_PRINTER |
| Device Link Profile | CLASS\_LINK |
| Color Space Conversion Profile | CLASS\_COLORSPACE |
| Abstract Profile | CLASS\_ABSTRACT |
| Named Color Profile | CLASS\_NAMED |
| Color Appearance Model Profile | CLASS\_CAMP |
| Color Gamut Map Model Profile | CLASS\_GMMP |

### `dwDataColorSpace`

A signature value that indicates the color space in which the profile data is defined. Can be any value from the [Color Space Constants](https://learn.microsoft.com/windows/win32/wcs/color-space-constants).

### `dwConnectionSpace`

A signature value that indicates the color space in which the profile connection space (PCS) is defined. Can be any of the following values.

| Profile Class | Signature |
|---------------|------------|
| XYZ | SPACE\_XYZ |
| Lab | SPACE\_Lab |

When the **dwClass** member is set to CLASS\_LINK, the PCS is taken from the **dwDataColorSpace** member.

### `dwSignature`

Reserved for internal use.

### `dwPlatform`

The primary platform for which the profile was created. The member can be set to any of the following values.

| Platform | Value |
|------------------------|--------|
| Apple Computer, Inc. | 'APPL' |
| Microsoft Corp. | 'MSFT' |
| Silicon Graphics, Inc. | 'SGI' |
| Sun Microsystems, Inc. | 'SUNW' |
| Taligent | 'TGNT' |

### `dwProfileFlags`

Bit flags containing hints that the CMM uses to interpret the profile data and can be set to one of the following values.

| Constant | Meaning |
|-----------------------|--------------------------------------------------------------------------------------------------------------------------|
| FLAG\_EMBEDDEDPROFILE | The profile is embedded in a bitmap file. |
| FLAG\_DEPENDENTONDATA | The profile can't be used independently of the embedded color data. Used for profiles that are embedded in bitmap files. |

### `dwManufacturer`

The identification number of the device profile manufacturer. All manufacturer identification numbers are registered with the ICC.

### `dwModel`

The device manufacturer's device model number. All model identification numbers are registered with the ICC.

### `dwAttributes`

Attributes of profile that can be any of the following values.

| Constant | Meaning |
|----------------------|------------------------------------------------------------------------------------------|
| ATTRIB\_TRANSPARENCY | Turns transparency on. If this flag is not used, the attribute is reflective by default. |
| ATTRIB\_MATTE | Turns matte display on. If this flag is not used, the attribute is glossy by default. |

### `dwRenderingIntent`

The profile rendering intent that can be set to one of the following values:

INTENT\_PERCEPTUAL

INTENT\_SATURATION

INTENT\_RELATIVE\_COLORIMETRIC

INTENT\_ABSOLUTE\_COLORIMETRIC

For more information, see [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `dwCreator`

Signature of the software that created the profile. Signatures are registered with the ICC.

### `dwDeviceClass`

Indicates the device class. A device class may have one of the following values.

| Profile Class | Signature |
|------------------------|----------------|
| Input Device Profile | CLASS\_SCANNER |
| Display Device Profile | CLASS\_MONITOR |
| Output Device Profile | CLASS\_PRINTER |

## Remarks

## See also

* [Further information](https://learn.microsoft.com/windows/win32/wcs/further-information)
* [Using device profiles with WCS](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs)
* [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents)