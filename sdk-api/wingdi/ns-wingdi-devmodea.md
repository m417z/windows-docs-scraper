# DEVMODEA structure

## Description

The **DEVMODE** data structure contains information about the initialization and environment of a printer or a display device.

## Members

### `dmDeviceName`

A zero-terminated character array that specifies the "friendly" name of the printer or display; for example, "PCL/HP LaserJet" in the case of PCL/HP LaserJet. This string is unique among device drivers. Note that this name may be truncated to fit in the **dmDeviceName** array.

### `dmSpecVersion`

The version number of the initialization data specification on which the structure is based. To ensure the correct version is used for any operating system, use DM_SPECVERSION.

### `dmDriverVersion`

The driver version number assigned by the driver developer.

### `dmSize`

Specifies the size, in bytes, of the **DEVMODE** structure, not including any private driver-specific data that might follow the structure's public members. Set this member to `sizeof (DEVMODE)` to indicate the version of the **DEVMODE** structure being used.

### `dmDriverExtra`

Contains the number of bytes of private driver-data that follow this structure. If a device driver does not use device-specific information, set this member to zero.

### `dmFields`

Specifies whether certain members of the **DEVMODE** structure have been initialized. If a member is initialized, its corresponding bit is set, otherwise the bit is clear. A driver supports only those **DEVMODE** members that are appropriate for the printer or display technology.

The following values are defined, and are listed here with the corresponding structure members.

| Value | Structure member |
| --- | --- |
| DM_ORIENTATION | **dmOrientation** |
| DM_PAPERSIZE | **dmPaperSize** |
| DM_PAPERLENGTH | **dmPaperLength** |
| DM_PAPERWIDTH | **dmPaperWidth** |
| DM_SCALE | **dmScale** |
| DM_COPIES | **dmCopies** |
| DM_DEFAULTSOURCE | **dmDefaultSource** |
| DM_PRINTQUALITY | **dmPrintQuality** |
| DM_POSITION | **dmPosition** |
| DM_DISPLAYORIENTATION | **dmDisplayOrientation** |
| DM_DISPLAYFIXEDOUTPUT | **dmDisplayFixedOutput** |
| DM_COLOR | **dmColor** |
| DM_DUPLEX | **dmDuplex** |
| DM_YRESOLUTION | **dmYResolution** |
| DM_TTOPTION | **dmTTOption** |
| DM_COLLATE | **dmCollate** |
| DM_FORMNAME | **dmFormName** |
| DM_LOGPIXELS | **dmLogPixels** |
| DM_BITSPERPEL | **dmBitsPerPel** |
| DM_PELSWIDTH | **dmPelsWidth** |
| DM_PELSHEIGHT | **dmPelsHeight** |
| DM_DISPLAYFLAGS | **dmDisplayFlags** |
| DM_NUP | **dmNup** |
| DM_DISPLAYFREQUENCY | **dmDisplayFrequency** |
| DM_ICMMETHOD | **dmICMMethod** |
| DM_ICMINTENT | **dmICMIntent** |
| DM_MEDIATYPE | **dmMediaType** |
| DM_DITHERTYPE | **dmDitherType** |
| DM_PANNINGWIDTH | **dmPanningWidth** |
| DM_PANNINGHEIGHT | **dmPanningHeight** |

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmOrientation`

For printer devices only, selects the orientation of the paper. This member can be either DMORIENT_PORTRAIT (1) or DMORIENT_LANDSCAPE (2).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPaperSize`

For printer devices only, selects the size of the paper to print on. This member can be set to zero if the length and width of the paper are both set by the **dmPaperLength** and **dmPaperWidth** members. Otherwise, the **dmPaperSize** member can be set to a device specific value greater than or equal to DMPAPER_USER or to one of the following predefined values.

| Value | Meaning |
| --- | --- |
| DMPAPER_LETTER | Letter, 8 1/2- by 11-inches |
| DMPAPER_LEGAL | Legal, 8 1/2- by 14-inches |
| DMPAPER_9X11 | 9- by 11-inch sheet |
| DMPAPER_10X11 | 10- by 11-inch sheet |
| DMPAPER_10X14 | 10- by 14-inch sheet |
| DMPAPER_15X11 | 15- by 11-inch sheet |
| DMPAPER_11X17 | 11- by 17-inch sheet |
| DMPAPER_12X11 | 12- by 11-inch sheet |
| DMPAPER_A2 | A2 sheet, 420 x 594-millimeters |
| DMPAPER_A3 | A3 sheet, 297- by 420-millimeters |
| DMPAPER_A3_EXTRA | A3 Extra 322 x 445-millimeters |
| DMPAPER_A3_EXTRA_TRAVERSE | A3 Extra Transverse 322 x 445-millimeters |
| DMPAPER_A3_ROTATED | A3 rotated sheet, 420- by 297-millimeters |
| DMPAPER_A3_TRAVERSE | A3 Transverse 297 x 420-millimeters |
| DMPAPER_A4 | A4 sheet, 210- by 297-millimeters |
| DMPAPER_A4_EXTRA | A4 sheet, 9.27 x 12.69 inches |
| DMPAPER_A4_PLUS | A4 Plus 210 x 330-millimeters |
| DMPAPER_A4_ROTATED | A4 rotated sheet, 297- by 210-millimeters |
| DMPAPER_A4SMALL | A4 small sheet, 210- by 297-millimeters |
| DMPAPER_A4_TRANSVERSE | A4 Transverse 210 x 297 millimeters |
| DMPAPER_A5 | A5 sheet, 148- by 210-millimeters |
| DMPAPER_A5_EXTRA | A5 Extra 174 x 235-millimeters |
| DMPAPER_A5_ROTATED | A5 rotated sheet, 210- by 148-millimeters |
| DMPAPER_A5_TRANSVERSE | A5 Transverse 148 x 210-millimeters |
| DMPAPER_A6 | A6 sheet, 105- by 148-millimeters |
| DMPAPER_A6_ROTATED | A6 rotated sheet, 148- by 105-millimeters |
| DMPAPER_A_PLUS | SuperA/A4 227 x 356 -millimeters |
| DMPAPER_B4 | B4 sheet, 250- by 354-millimeters |
| DMPAPER_B4_JIS_ROTATED | B4 (JIS) rotated sheet, 364- by 257-millimeters |
| DMPAPER_B5 | B5 sheet, 182- by 257-millimeter paper |
| DMPAPER_B5_EXTRA | B5 (ISO) Extra 201 x 276-millimeters |
| DMPAPER_B5_JIS_ROTATED | B5 (JIS) rotated sheet, 257- by 182-millimeters |
| DMPAPER_B6_JIS | B6 (JIS) sheet, 128- by 182-millimeters |
| DMPAPER_B6_JIS_ROTATED | B6 (JIS) rotated sheet, 182- by 128-millimeters |
| DMPAPER_B_PLUS | SuperB/A3 305 x 487-millimeters |
| DMPAPER_CSHEET | C Sheet, 17- by 22-inches |
| DMPAPER_DBL_JAPANESE_POSTCARD | Double Japanese Postcard, 200- by 148-millimeters |
| DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED | Double Japanese Postcard Rotated, 148- by 200-millimeters |
| DMPAPER_DSHEET | D Sheet, 22- by 34-inches |
| DMPAPER_ENV_9 | #9 Envelope, 3 7/8- by 8 7/8-inches |
| DMPAPER_ENV_10 | #10 Envelope, 4 1/8- by 9 1/2-inches |
| DMPAPER_ENV_11 | #11 Envelope, 4 1/2- by 10 3/8-inches |
| DMPAPER_ENV_12 | #12 Envelope, 4 3/4- by 11-inches |
| DMPAPER_ENV_14 | #14 Envelope, 5- by 11 1/2-inches |
| DMPAPER_ENV_C5 | C5 Envelope, 162- by 229-millimeters |
| DMPAPER_ENV_C3 | C3 Envelope, 324- by 458-millimeters |
| DMPAPER_ENV_C4 | C4 Envelope, 229- by 324-millimeters |
| DMPAPER_ENV_C6 | C6 Envelope, 114- by 162-millimeters |
| DMPAPER_ENV_C65 | C65 Envelope, 114- by 229-millimeters |
| DMPAPER_ENV_B4 | B4 Envelope, 250- by 353-millimeters |
| DMPAPER_ENV_B5 | B5 Envelope, 176- by 250-millimeters |
| DMPAPER_ENV_B6 | B6 Envelope, 176- by 125-millimeters |
| DMPAPER_ENV_DL | DL Envelope, 110- by 220-millimeters |
| DMPAPER_ENV_INVITE | Envelope Invite 220 x 220 mm |
| DMPAPER_ENV_ITALY | Italy Envelope, 110- by 230-millimeters |
| DMPAPER_ENV_MONARCH | Monarch Envelope, 3 7/8- by 7 1/2-inches |
| DMPAPER_ENV_PERSONAL | 6 3/4 Envelope, 3 5/8- by 6 1/2-inches |
| DMPAPER_ESHEET | E Sheet, 34- by 44-inches |
| DMPAPER_EXECUTIVE | Executive, 7 1/4- by 10 1/2-inches |
| DMPAPER_FANFOLD_US | US Std Fanfold, 14 7/8- by 11-inches |
| DMPAPER_FANFOLD_STD_GERMAN | German Std Fanfold, 8 1/2- by 12-inches |
| DMPAPER_FANFOLD_LGL_GERMAN | German Legal Fanfold, 8 - by 13-inches |
| DMPAPER_FOLIO | Folio, 8 1/2- by 13-inch paper |
| DMPAPER_ISO_B4 | B4 (ISO) 250- by 353-millimeters paper |
| DMPAPER_JAPANESE_POSTCARD | Japanese Postcard, 100- by 148-millimeters |
| DMPAPER_JAPANESE_POSTCARD_ROTATED | Japanese Postcard Rotated, 148- by 100-millimeters |
| DMPAPER_JENV_CHOU3 | Japanese Envelope Chou #3 |
| DMPAPER_JENV_CHOU3_ROTATED | Japanese Envelope Chou #3 Rotated |
| DMPAPER_JENV_CHOU4 | Japanese Envelope Chou #4 |
| DMPAPER_JENV_CHOU4_ROTATED | Japanese Envelope Chou #4 Rotated |
| DMPAPER_JENV_KAKU2 | Japanese Envelope Kaku #2 |
| DMPAPER_JENV_KAKU2_ROTATED | Japanese Envelope Kaku #2 Rotated |
| DMPAPER_JENV_KAKU3 | Japanese Envelope Kaku #3 |
| DMPAPER_JENV_KAKU3_ROTATED | Japanese Envelope Kaku #3 Rotated |
| DMPAPER_JENV_YOU4 | Japanese Envelope You #4 |
| DMPAPER_JENV_YOU4_ROTATED | Japanese Envelope You #4 Rotated |
| DMPAPER_LAST | DMPAPER_PENV_10_ROTATED |
| DMPAPER_LEDGER | Ledger, 17- by 11-inches |
| DMPAPER_LEGAL_EXTRA | Legal Extra 9 1/2 x 15 inches. |
| DMPAPER_LETTER_EXTRA | Letter Extra 9 1/2 x 12 inches. |
| DMPAPER_LETTER_EXTRA_TRANSVERSE | Letter Extra Transverse 9 1/2 x 12 inches. |
| DMPAPER_LETTER_ROTATED | Letter Rotated 11 by 8 1/2 inches |
| DMPAPER_LETTERSMALL | Letter Small, 8 1/2- by 11-inches |
| DMPAPER_LETTER_TRANSVERSE | Letter Transverse 8 1/2 x 11-inches |
| DMPAPER_NOTE | Note, 8 1/2- by 11-inches |
| DMPAPER_P16K | PRC 16K, 146- by 215-millimeters |
| DMPAPER_P16K_ROTATED | PRC 16K Rotated, 215- by 146-millimeters |
| DMPAPER_P32K | PRC 32K, 97- by 151-millimeters |
| DMPAPER_P32K_ROTATED | PRC 32K Rotated, 151- by 97-millimeters |
| DMPAPER_P32KBIG | PRC 32K(Big) 97- by 151-millimeters |
| DMPAPER_P32KBIG_ROTATED | PRC 32K(Big) Rotated, 151- by 97-millimeters |
| DMPAPER_PENV_1 | PRC Envelope #1, 102- by 165-millimeters |
| DMPAPER_PENV_1_ROTATED | PRC Envelope #1 Rotated, 165- by 102-millimeters |
| DMPAPER_PENV_2 | PRC Envelope #2, 102- by 176-millimeters |
| DMPAPER_PENV_2_ROTATED | PRC Envelope #2 Rotated, 176- by 102-millimeters |
| DMPAPER_PENV_3 | PRC Envelope #3, 125- by 176-millimeters |
| DMPAPER_PENV_3_ROTATED | PRC Envelope #3 Rotated, 176- by 125-millimeters |
| DMPAPER_PENV_4 | PRC Envelope #4, 110- by 208-millimeters |
| DMPAPER_PENV_4_ROTATED | PRC Envelope #4 Rotated, 208- by 110-millimeters |
| DMPAPER_PENV_5 | PRC Envelope #5, 110- by 220-millimeters |
| DMPAPER_PENV_5_ROTATED | PRC Envelope #5 Rotated, 220- by 110-millimeters |
| DMPAPER_PENV_6 | PRC Envelope #6, 120- by 230-millimeters |
| DMPAPER_PENV_6_ROTATED | PRC Envelope #6 Rotated, 230- by 120-millimeters |
| DMPAPER_PENV_7 | PRC Envelope #7, 160- by 230-millimeters |
| DMPAPER_PENV_7_ROTATED | PRC Envelope #7 Rotated, 230- by 160-millimeters |
| DMPAPER_PENV_8 | PRC Envelope #8, 120- by 309-millimeters |
| DMPAPER_PENV_8_ROTATED | PRC Envelope #8 Rotated, 309- by 120-millimeters |
| DMPAPER_PENV_9 | PRC Envelope #9, 229- by 324-millimeters |
| DMPAPER_PENV_9_ROTATED | PRC Envelope #9 Rotated, 324- by 229-millimeters |
| DMPAPER_PENV_10 | PRC Envelope #10, 324- by 458-millimeters |
| DMPAPER_PENV_10_ROTATED | PRC Envelope #10 Rotated, 458- by 324-millimeters |
| DMPAPER_QUARTO | Quarto, 215- by 275-millimeter paper |
| DMPAPER_STATEMENT | Statement, 5 1/2- by 8 1/2-inches |
| DMPAPER_TABLOID | Tabloid, 11- by 17-inches |
| DMPAPER_TABLOID_EXTRA | Tabloid, 11.69 x 18-inches |

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPaperLength`

For printer devices only, overrides the length of the paper specified by the **dmPaperSize** member, either for custom paper sizes or for devices such as dot-matrix printers that can print on a page of arbitrary length. These values, along with all other values in this structure that specify a physical length, are in tenths of a millimeter.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPaperWidth`

For printer devices only, overrides the width of the paper specified by the **dmPaperSize** member.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmScale`

Specifies the factor by which the printed output is to be scaled. The apparent page size is scaled from the physical page size by a factor of **dmScale** /100. For example, a letter-sized page with a **dmScale** value of 50 would contain as much data as a page of 17- by 22-inches because the output text and graphics would be half their original height and width.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmCopies`

Selects the number of copies printed if the device supports multiple-page copies.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmDefaultSource`

Specifies the paper source. To retrieve a list of the available paper sources for a printer, use the [DeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-devicecapabilitiesa) function with the DC_BINS flag.

This member can be one of the following values, or it can be a device-specific value greater than or equal to DMBIN_USER.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPrintQuality`

Specifies the printer resolution. There are four predefined device-independent values:

If a positive value is specified, it specifies the number of dots per inch (DPI) and is therefore device dependent.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.dmPosition`

For display devices only, a [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure that indicates the positional coordinates of the display device in reference to the desktop area. The primary display device is always located at coordinates (0,0).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.dmDisplayOrientation`

For display devices only, the orientation at which images should be presented. If DM_DISPLAYORIENTATION is not set, this member must be zero. If DM_DISPLAYORIENTATION is set, this member must be one of the following values

| Value | Meaning |
| --- | --- |
| DMDO_DEFAULT | The display orientation is the natural orientation of the display device; it should be used as the default. |
| DMDO_90 | The display orientation is rotated 90 degrees (measured counter-clockwise) from DMDO_DEFAULT. |
| DMDO_180 | The display orientation is rotated 180 degrees (measured counter-clockwise) from DMDO_DEFAULT. |
| DMDO_270 | The display orientation is rotated 270 degrees (measured counter-clockwise) from DMDO_DEFAULT. |

To determine whether the display orientation is portrait or landscape orientation, check the ratio of **dmPelsWidth** to **dmPelsHeight**.

**Windows 2000:** Not supported.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.dmDisplayFixedOutput`

For fixed-resolution display devices only, how the display presents a low-resolution mode on a higher-resolution display. For example, if a display device's resolution is fixed at 1024 x 768 pixels but its mode is set to 640 x 480 pixels, the device can either display a 640 x 480 image somewhere in the interior of the 1024 x 768 screen space or stretch the 640 x 480 image to fill the larger screen space. If DM_DISPLAYFIXEDOUTPUT is not set, this member must be zero. If DM_DISPLAYFIXEDOUTPUT is set, this member must be one of the following values.

| Value | Meaning |
| --- | --- |
| DMDFO_DEFAULT | The display's default setting. |
| DMDFO_CENTER | The low-resolution image is centered in the larger screen space. |
| DMDFO_STRETCH | The low-resolution image is stretched to fill the larger screen space. |

**Windows 2000:** Not supported.

### `dmColor`

Switches between color and monochrome on color printers. The following are the possible values:

* DMCOLOR_COLOR
* DMCOLOR_MONOCHROME

### `dmDuplex`

Selects duplex or double-sided printing for printers capable of duplex printing. Following are the possible values.

| Value | Meaning |
| --- | --- |
| DMDUP_SIMPLEX | Normal (nonduplex) printing. |
| DMDUP_HORIZONTAL | Short-edge binding, that is, the long edge of the page is horizontal. |
| DMDUP_VERTICAL | Long-edge binding, that is, the long edge of the page is vertical. |

### `dmYResolution`

Specifies the y-resolution, in dots per inch, of the printer. If the printer initializes this member, the **dmPrintQuality** member specifies the x-resolution, in dots per inch, of the printer.

### `dmTTOption`

Specifies how TrueType fonts should be printed. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| DMTT_BITMAP | Prints TrueType fonts as graphics. This is the default action for dot-matrix printers. |
| DMTT_DOWNLOAD | Downloads TrueType fonts as soft fonts. This is the default action for Hewlett-Packard printers that use Printer Control Language (PCL). |
| DMTT_DOWNLOAD_OUTLINE | Downloads TrueType fonts as outline soft fonts. |
| DMTT_SUBDEV | Substitutes device fonts for TrueType fonts. This is the default action for PostScript printers. |

### `dmCollate`

Specifies whether collation should be used when printing multiple copies. (This member is ignored unless the printer driver indicates support for collation by setting the **dmFields** member to DM_COLLATE.) This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| DMCOLLATE_TRUE | Collate when printing multiple copies. |
| DMCOLLATE_FALSE | Do not collate when printing multiple copies. |

### `dmFormName`

A zero-terminated character array that specifies the name of the form to use; for example, "Letter" or "Legal". A complete set of names can be retrieved by using the [EnumForms](https://learn.microsoft.com/windows/desktop/printdocs/enumforms) function.

### `dmLogPixels`

The number of pixels per logical inch. Printer drivers do not use this member.

### `dmBitsPerPel`

Specifies the color resolution, in bits per pixel, of the display device (for example: 4 bits for 16 colors, 8 bits for 256 colors, or 16 bits for 65,536 colors). Display drivers use this member, for example, in the [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa) function. Printer drivers do not use this member.

### `dmPelsWidth`

Specifies the width, in pixels, of the visible device surface. Display drivers use this member, for example, in the [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa) function. Printer drivers do not use this member.

### `dmPelsHeight`

Specifies the height, in pixels, of the visible device surface. Display drivers use this member, for example, in the [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa) function. Printer drivers do not use this member.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.dmDisplayFlags`

Specifies the device's display mode. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| DM_GRAYSCALE | Specifies that the display is a noncolor device. If this flag is not set, color is assumed. This flag is no longer valid. |
| DM_INTERLACED | Specifies that the display mode is interlaced. If the flag is not set, noninterlaced is assumed. |

Display drivers use this member, for example, in the [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa) function. Printer drivers do not use this member.

### `DUMMYUNIONNAME2.dmNup`

Specifies where the NUP is done. It can be one of the following.

| Value | Meaning |
| --- | --- |
| DMNUP_SYSTEM | The print spooler does the NUP. |
| DMNUP_ONEUP | The application does the NUP. |

### `dmDisplayFrequency`

Specifies the frequency, in hertz (cycles per second), of the display device in a particular mode. This value is also known as the display device's vertical refresh rate. Display drivers use this member. It is used, for example, in the [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa) function. Printer drivers do not use this member.

When you call the [EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa) function, the **dmDisplayFrequency** member may return with the value 0 or 1. These values represent the display hardware's default refresh rate. This default rate is typically set by switches on a display card or computer motherboard, or by a configuration program that does not use display functions such as [ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa).

### `dmICMMethod`

Specifies how ICM is handled. For a non-ICM application, this member determines if ICM is enabled or disabled. For ICM applications, the system examines this member to determine how to handle ICM support. This member can be one of the following predefined values, or a driver-defined value greater than or equal to the value of DMICMMETHOD_USER.

| Value | Meaning |
| --- | --- |
| DMICMMETHOD_NONE | Specifies that ICM is disabled. |
| DMICMMETHOD_SYSTEM | Specifies that ICM is handled by Windows. |
| DMICMMETHOD_DRIVER | Specifies that ICM is handled by the device driver. |
| DMICMMETHOD_DEVICE | Specifies that ICM is handled by the destination device. |

The printer driver must provide a user interface for setting this member. Most printer drivers support only the DMICMMETHOD_SYSTEM or DMICMMETHOD_NONE value. Drivers for PostScript printers support all values.

### `dmICMIntent`

Specifies which color matching method, or intent, should be used by default. This member is primarily for non-ICM applications. ICM applications can establish intents by using the ICM functions. This member can be one of the following predefined values, or a driver defined value greater than or equal to the value of DMICM_USER.

| Value | Meaning |
| --- | --- |
| DMICM_ABS_COLORIMETRIC | Color matching should optimize to match the exact color requested without white point mapping. This value is most appropriate for use with proofing. |
| DMICM_COLORIMETRIC | Color matching should optimize to match the exact color requested. This value is most appropriate for use with business logos or other images when an exact color match is desired. |
| DMICM_CONTRAST | Color matching should optimize for color contrast. This value is the most appropriate choice for scanned or photographic images when dithering is desired. |
| DMICM_SATURATE | Color matching should optimize for color saturation. This value is the most appropriate choice for business graphs when dithering is not desired. |

### `dmMediaType`

Specifies the type of media being printed on. The member can be one of the following predefined values, or a driver-defined value greater than or equal to the value of DMMEDIA_USER.

| Value | Meaning |
| --- | --- |
| DMMEDIA_STANDARD | Plain paper. |
| DMMEDIA_GLOSSY | Glossy paper. |
| DMMEDIA_TRANSPARENCY | Transparent film. |

 To retrieve a list of the available media types for a printer, use the [DeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-devicecapabilitiesa) function with the DC_MEDIATYPES flag.

### `dmDitherType`

Specifies how dithering is to be done. The member can be one of the following predefined values, or a driver-defined value greater than or equal to the value of DMDITHER_USER.

| Value | Meaning |
| --- | --- |
| DMDITHER_NONE | No dithering. |
| DMDITHER_COARSE | Dithering with a coarse brush. |
| DMDITHER_FINE | Dithering with a fine brush. |
| DMDITHER_LINEART | Line art dithering, a special dithering method that produces well defined borders between black, white, and gray scaling. It is not suitable for images that include continuous graduations in intensity and hue, such as scanned photographs. |
| DMDITHER_GRAYSCALE | Device does gray scaling. |

### `dmReserved1`

Not used; must be zero.

### `dmReserved2`

Not used; must be zero.

### `dmPanningWidth`

This member must be zero.

### `dmPanningHeight`

This member must be zero.

##### - dmDefaultSource.DMBIN_AUTO

##### - dmDefaultSource.DMBIN_CASSETTE

##### - dmDefaultSource.DMBIN_ENVELOPE

##### - dmDefaultSource.DMBIN_ENVMANUAL

##### - dmDefaultSource.DMBIN_FIRST

##### - dmDefaultSource.DMBIN_FORMSOURCE

##### - dmDefaultSource.DMBIN_LARGECAPACITY

##### - dmDefaultSource.DMBIN_LARGEFMT

##### - dmDefaultSource.DMBIN_LAST

##### - dmDefaultSource.DMBIN_LOWER

##### - dmDefaultSource.DMBIN_MANUAL

##### - dmDefaultSource.DMBIN_MIDDLE

##### - dmDefaultSource.DMBIN_ONLYONE

##### - dmDefaultSource.DMBIN_SMALLFMT

##### - dmDefaultSource.DMBIN_TRACTOR

##### - dmDefaultSource.DMBIN_UPPER

##### - dmPrintQuality.DMRES_DRAFT

##### - dmPrintQuality.DMRES_HIGH

##### - dmPrintQuality.DMRES_LOW

##### - dmPrintQuality.DMRES_MEDIUM

## Remarks

A device driver's private data follows the public portion of the **DEVMODE** structure. The size of the public data can vary for different versions of the structure. The **dmSize** member specifies the number of bytes of public data, and the **dmDriverExtra** member specifies the number of bytes of private data.

> [!NOTE]
> The wingdi.h header defines DEVMODE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AdvancedDocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/advanceddocumentproperties)

[ChangeDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changedisplaysettingsa)

[CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[CreateIC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createica)

[DeviceCapabilities](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-devicecapabilitiesa)

[DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties)

[EnumDisplaySettings](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaysettingsa)

[OpenPrinter](https://learn.microsoft.com/windows/desktop/printdocs/openprinter)

[Print Spooler API Structures](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-structures)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)