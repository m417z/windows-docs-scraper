# SetICMMode function

## Description

The **SetICMMode** function causes Image Color Management to be enabled, disabled, or queried on a given device context (DC).

## Parameters

### `hdc`

Identifies handle to the device context.

### `mode`

Turns on and off image color management. This parameter can take one of the following constant values.

| Value | Meaning |
| --- | --- |
| **ICM_ON** | Turns on color management. Turns off old-style color correction of halftones. |
| **ICM_OFF** | Turns off color management. Turns on old-style color correction of halftones. |
| **ICM_QUERY** | Queries the current state of color management. |
| **ICM_DONE_OUTSIDEDC** | Turns off color management inside DC. Under Windows 2000, also turns off old-style color correction of halftones. Not supported under Windows 95. |

## Return value

If this function succeeds, the return value is a nonzero value.

If this function fails, the return value is zero.

If ICM_QUERY is specified and the function succeeds, the nonzero value returned is ICM_ON or ICM_OFF to indicate the current mode.

## Remarks

If the system cannot find an ICC color profile to match the state of the device, **SetICMMode** fails and returns zero.

Once WCS is enabled for a device context (DC), colors passed into the DC using most Win32 API functions are color matched. The primary exceptions are **BitBlt** and **StretchBlt**. The assumption is that when performing a bit block transfer (blit) from one DC to another, the two DCs are already compatible and need no color correction. If this is not the case, color correction may be performed. Specifically, if a device independent bitmap (DIB) is used as the source for a blit, and the blit is performed into a DC that has WCS enabled, color matching will be performed. If this is not what you want, turn WCS off for the destination DC by calling **SetICMMode** before calling **BitBlt** or **StretchBlt**.

If the **CreateCompatibleDC** function is used to create a bitmap in a DC, it is possible for the bitmap to be color matched twice, once when it is created and once when a blit is performed. The reason is that a bitmap in a DC created by the **CreateCompatibleDC** function acquires the current brush, pens, and palette of the source DC. However, WCS will be disabled by default for the new DC. If WCS is later enabled for the new DC by using the **SetICMMode** function, a color correction will be done. To prevent double color corrections through the use of the **CreateCompatibleDC** function, use the **SetICMMode** function to turn WCS off for the source DC before the **CreateCompatibleDC** function is called.

When a compatible DC is created from a printer's DC (see **CreateCompatibleDC** ), the default is for color matching to always be performed if it is enabled for the printer's DC. The default color profile for the printer is used when a blit is performed into the printer's DC using **SetDIBitsToDevice** or **StretchDIBits**. If this is not what you want, turn WCS off for the printer's DC by calling **SetICMMode** before calling **SetDIBitsToDevice** or **StretchDIBits**.

Also, when printing to a printer's DC with WCS turned on, the **SetICMMode** function needs to be called after every call to the **StartPage** function to turn back on WCS. The **StartPage** function calls the **RestoreDC** and **SaveDC** functions, which result in WCS being turned off for the printer's DC.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)
* [BitBlt](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-bitblt)
* [CreateCompatibleDC](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-createcompatibledc)
* [SetDIBitsToDevice](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-setdibitstodevice)
* [StartPage](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-startpage)
* [StretchBlt](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-stretchblt)
* [StretchDIBits](https://learn.microsoft.com/windows/win32/api/wingdi/nf-wingdi-stretchdibits)