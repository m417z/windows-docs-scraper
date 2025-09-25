## Description

Contains information that describes the contents of a device profile file. This header occurs at the beginning of a device profile file.

## Members

### `phSize`

The size of the profile in bytes.

### `phCMMType`

The identification number of the CMM that is used in the profile. Identification numbers are registered with the ICC.

### `phVersion`

The version number of the profile. The version number is determined by the ICC. The current major version number is 02h. The current minor version number is 10h. The major and minor version numbers are in binary coded decimal (BCD). They must be stored in the following format.

| Byte Number | Contents |
|-------------|---------------------------------------------------------------------------------------------------------------------------|
| 0 | Major version number in BCD. |
| 1 | Minor version number in the most significant nibble of this byte. Bug fix version number in the least significant nibble. |
| 2 | Reserved. Must be set to 0. |
| 3 | Reserved. Must be set to 0. |

### `phClass`

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

### `phDataColorSpace`

A signature value that indicates the color space in which the profile data is defined. The member can be any of value from the [Color Space Constants](https://learn.microsoft.com/windows/win32/wcs/color-space-constants).

### `phConnectionSpace`

A signature value that indicates the color space in which the profile connection space (PCS) is defined. The member can be any of the following values.

| Profile Class | Signature |
|---------------|------------|
| XYZ | SPACE\_XYZ |
| Lab | SPACE\_Lab |

When the **phClass** member is set to CLASS\_LINK, the PCS is taken from the **phDataColorSpace** member.

### `phDateTime`

The date and time that the profile was created.

### `phSignature`

Reserved for internal use.

### `phPlatform`

The primary platform for which the profile was created. The primary platform can be set to any of the following values.

| Platform | Value |
|------------------------|--------|
| Apple Computer, Inc. | 'APPL' |
| Microsoft Corp. | 'MSFT' |
| Silicon Graphics, Inc. | 'SGI' |
| Sun Microsystems, Inc. | 'SUNW' |
| Taligent | 'TGNT' |

### `phProfileFlags`

Bit flags containing hints that the CMM uses to interpret the profile data. The member can be set to the following values.

| Constant | Meaning |
| --- | --- |
| |  | | --- | | FLAG_EMBEDDEDPROFILE | | |  | | --- | | The profile is embedded in a bitmap file. | |
| |  | | --- | | FLAG_DEPENDENTONDATA | | |  | | --- | | The profile can't be used independently of the embedded color data. Used for profiles that are embedded in bitmap files. | |

### `phManufacturer`

The identification number of the device profile manufacturer. All manufacturer identification numbers are registered with the ICC.

### `phModel`

The device manufacturer's device model number. All model identification numbers are registered with the ICC.

### `phAttributes`

Attributes of profile. The profile attributes can be any of the following values.

| Constant | Meaning |
|----------------------|------------------------------------------------------------------------------------------|
| ATTRIB\_TRANSPARENCY | Turns transparency on. If this flag is not used, the attribute is reflective by default. |
| ATTRIB\_MATTE | Turns matte display on. If this flag is not used, the attribute is glossy by default. |

### `phRenderingIntent`

The profile rendering intent. The member can be set to one of the following values:

INTENT\_PERCEPTUAL

INTENT\_SATURATION

INTENT\_RELATIVE\_COLORIMETRIC

INTENT\_ABSOLUTE\_COLORIMETRIC

For more information, see [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

### `phIlluminant`

Profile illuminant.

### `phCreator`

Signature of the software that created the profile. Signatures are registered with the ICC.

### `phReserved`

Reserved.

## Remarks

## See also

* [Further information](https://learn.microsoft.com/windows/win32/wcs/further-information)
* [Using device profiles with WCS](https://learn.microsoft.com/windows/win32/wcs/using-device-profiles-with-wcs)
* [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents)