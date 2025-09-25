# BlackInformation structure

## Description

Contains information for device models that have a black color channel.

## Members

### `fBlackOnly`

### `blackWeight`

A value between 0.0 and 1.0 that indicates the relative amount of black to use in the output. A value of 0.0 means that no black is used; a value of 1.0 means that the maximum amount of black is used.

#### - bBlackOnly

An indicator whether the source color contains only black. This value can only be true if both of the following apply:

* the source device has a black channel
* the [PRESERVEBLACK](https://learn.microsoft.com/previous-versions/ms536577(v=vs.85)) flag is set to **true**. This flag is in the *dwFlags* parameter of a Color Management Module (CMM) transform function.

## Remarks

If the source device does not support a black channel, then WCS sets **bBlackOnly** to **FALSE**.

If **bBlackOnly** is **TRUE**, then WCS generates an output device control value where, at most, the black channel will be non-zero. This only happens if the **BlackPreservation** flag was set in WCS. Note that in such cases, the device model may not be providing the closest colorimetric match to the supplied value.

Black preservation is only performed when both the source and destination devices support a black channel. If black is being preserved with these devices, then for each source device control value, where all channels other than the black channel are zero, the **bBlackOnly** flag is **TRUE**. Note that this means that a value where all channels are zero will also set **bBlackOnly** to **TRUE**.

**blackWeight** gives us information about the device control values used in the source device.

* For source devices with a black channel, **blackWeight** is set to the black value.
* For source devices without a black channel, the black weight is computed using a combination of *color purity* and *relative lightness*.*Color purity* is defined as (maxColorant - minColorant)/maxColorant

  *Relative lightness* is defined as (the lightness of the color in appearance space - minimum lightness of destination device) / (maximum lightness of destination device - minimum lightness of destination device)

  For RGB devices, blackWeight = (1 - colorPurity) * (1 - relativeLightness)

  For CMYK devices, blackWeight = colorPurity * (1 - relativeLightness)

  WCS is responsible for initializing the **BlackInformation** structure.

If **bBlackOnly** is **FALSE**, then the baseline device models for devices with a black channel will use the **blackWeight** to guide the creation of a colorimetrically appropriate output pixel value. For CMYK devices, **blackWeight** provides WCS's initial estimation of a K value and it searches for C, M, and Y values that will lead to the correct colorimetry. If it does not find a match, it adjusts the K value and searches again.

You can set plug-ins to either support or ignore the **BlackInformation**.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Structures](https://learn.microsoft.com/windows/win32/wcs/structures)