## Description

The DEVMODEW structure is used for specifying characteristics of display and print devices in the Unicode (wide) character set.

## Members

### `dmDeviceName`

For a display, specifies the name of the display driver's DLL; for example, "perm3dd" for the 3Dlabs Permedia3 display driver.

For a printer, specifies the "friendly name"; for example, "PCL/HP LaserJet" in the case of PCL/HP LaserJet. If the name is greater than CCHDEVICENAME characters in length, the spooler truncates it to fit in the array.

### `dmSpecVersion`

Specifies the version number of this DEVMODEW structure. The current version number is identified by the DM_SPECVERSION constant in *wingdi.h*.

### `dmDriverVersion`

For a printer, specifies the printer driver version number assigned by the printer driver developer.

Display drivers can set this member to DM_SPECVERSION.

### `dmSize`

Specifies the size in bytes of the public DEVMODEW structure, not including any private, driver-specified members identified by the **dmDriverExtra** member.

### `dmDriverExtra`

Specifies the number of bytes of private driver data that follow the public structure members. If a device driver does not provide private DEVMODEW members, this member should be set to zero.

### `dmFields`

Specifies bit flags identifying which of the following DEVMODEW members are in use. For example, the DM_ORIENTATION flag is set when the **dmOrientation** member contains valid data. The DM_XXX flags are defined in *wingdi.h*.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmOrientation`

For printers, specifies the paper orientation. This member can be either DMORIENT_PORTRAIT or DMORIENT_LANDSCAPE.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPaperSize`

For printers, specifies the size of the paper to be printed on. This member must be zero if the length and width of the paper are specified by the **dmPaperLength** and **dmPaperWidth** members. Otherwise, the **dmPaperSize** member must be one of the DMPAPER-prefixed constants defined in *wingdi.h*.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPaperLength`

For printers, specifies the length of the paper, in units of 1/10 of a millimeter. This value overrides the length of the paper specified by the **dmPaperSize** member, and is used if the paper is of a custom size, or if the device is a dot matrix printer, which can print a page of arbitrary length.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPaperWidth`

For printers, specifies the width of the paper, in units of 1/10 of a millimeter. This value overrides the width of the paper specified by the **dmPaperSize** member. This member must be used if **dmPaperLength** is used.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmScale`

For printers, specifies the percentage by which the image is to be scaled for printing. The image's page size is scaled to the physical page by a factor of **dmScale**/100. For example, a 17-inch by 22-inch image with a scale value of 100 requires 17x22-inch paper, while the same image with a scale value of 50 should print as half-sized and fit on letter-sized paper.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmCopies`

For printers, specifies the number of copies to be printed, if the device supports multiple copies.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmDefaultSource`

For printers, specifies the printer's default input bin. This must be one of the DMBIN-prefixed constants defined in *wingdi.h*. If the specified constant is DMBIN_FORMSOURCE, the input bin should be selected automatically.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.dmPrintQuality`

For printers, specifies the printer resolution. The following negative constant values are defined in *wingdi.h*:

DMRES_HIGH

DMRES_MEDIUM

DMRES_LOW

DMRES_DRAFT

If a positive value is specified, it represents the number of dots per inch (DPI) for the *x* resolution, and the *y* resolution is specified by **dmYResolution**.

This member is not used for displays.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.dmPosition`

For displays, specifies a [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structure containing the x- and y-coordinates of upper-left corner of the display, in desktop coordinates. This member is used to determine the relative position of monitors in a multiple monitor environment.

This member is not used for printers.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.dmDisplayOrientation`

This member is defined only for Windows XP and later.

For displays, specifies the orientation at which images should be presented. When the DM_DISPLAYORIENTATION bit is not set in the **dmFields** member, this member must be set to zero. When the DM_DISPLAYORIENTATION bit is set in the **dmFields** member, this member must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| DMDO_DEFAULT | The current mode's display device orientation is the natural orientation of the device, and should be used as the default. |
| DMDO_90 | The display device orientation is 90 degrees (measured counter-clockwise) from that of DMDO_DEFAULT. |
| DMDO_180 | The display device orientation is 180 degrees (measured counter-clockwise) from that of DMDO_DEFAULT. |
| DMDO_270 | The display device orientation is 270 degrees (measured counter-clockwise) from that of DMDO_DEFAULT. |

This member is not used for printers.

For more information, see [Returning Display Modes: DrvGetModes](https://learn.microsoft.com/windows-hardware/drivers/display/returning-display-modes--drvgetmodes).

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME2.dmDisplayFixedOutput`

This member is defined only for Windows XP and later.

For fixed-resolution displays, specifies how the device can present a lower-resolution mode on a higher-resolution display. For example, if a display device's resolution is fixed at 1024 X 768, and its mode is set to 640 x 480, the device can either display a 640 X 480 image within the 1024 X 768 screen space, or stretch the 640 X 480 image to fill the larger screen space.

When the DM_DISPLAYFIXEDOUTPUT bit is not set in the **dmFields** member, this member must be set to zero. When the DM_DISPLAYFIXEDOUTPUT bit is set in the **dmFields** member, this member must be set to one of the following values:

| Value | Meaning |
| --- | --- |
| DMDFO_CENTER | The display device presents a lower resolution mode image by centering it in the larger screen space. |
| DMDFO_STRETCH | The display device presents a lower-resolution mode image by stretching it to fill the larger screen space. |

This member is not used for printers.

For more information, see [Returning Display Modes: DrvGetModes](https://learn.microsoft.com/windows-hardware/drivers/display/returning-display-modes--drvgetmodes).

### `dmColor`

For printers, specifies whether a color printer should print color or monochrome. This member can be one of DMCOLOR_COLOR or DMCOLOR_MONOCHROME.

This member is not used for displays.

### `dmDuplex`

For printers, specifies duplex (double-sided) printing for duplex-capable printers. This member can be one of the following values:

#### DMDUP_HORIZONTAL

Print double-sided, using short edge binding.

#### DMDUP_SIMPLEX

Print single-sided.

#### DMDUP_VERTICAL

Print double-sided, using long edge binding.

This member is not used for displays.

### `dmYResolution`

For printers, specifies the *y* resolution of the printer, in DPI. If this member is used, the **dmPrintQuality** member specifies the *x* resolution.

This member is not used for displays.

### `dmTTOption`

For printers, specifies how TrueType fonts should be printed. This member must be one of the DMTT-prefixed constants defined in *wingdi.h*.

This member is not used for displays.

### `dmCollate`

For printers, specifies whether multiple copies should be collated. This member can be one of the following values:

#### DMCOLLATE_TRUE

Collate when printing multiple copies.

#### DMCOLLATE_FALSE

Do not collate when printing multiple copies.

This member is not used for displays.

### `dmFormName`

For printers, specifies the name of the form to use; such as "Letter" or "Legal". This must be a name that can be obtain by calling the Win32 [EnumForms](https://learn.microsoft.com/windows/win32/printdocs/enumforms) function.

This member is not used for displays.

### `dmLogPixels`

For displays, specifies the number of logical pixels per inch of a display device and should be equal to the **ulLogPixels** member of the [GDIINFO](https://learn.microsoft.com/windows/win32/api/winddi/ns-winddi-gdiinfo) structure.

This member is not used for printers.

### `dmBitsPerPel`

For displays, specifies the color resolution, in bits per pixel, of a display device.

This member is not used for printers.

### `dmPelsWidth`

For displays, specifies the width, in pixels, of the visible device surface.

This member is not used for printers.

### `dmPelsHeight`

For displays, specifies the height, in pixels, of the visible device surface.

This member is not used for printers.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.dmDisplayFlags`

Specifies the device's display mode. This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| DM_GRAYSCALE | Specifies that the display is a noncolor device. If this flag is not set, color is assumed. This flag is no longer valid. |
| DM_INTERLACED | Specifies that the display mode is interlaced. If the flag is not set, noninterlaced is assumed. |

Display drivers use this member; for example, in the [ChangeDisplaySettings](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-changedisplaysettingsa) function. Printer drivers don't use this member.

### `DUMMYUNIONNAME2.dmNup`

For printers, specifies whether the print system handles "N-up" printing (playing multiple EMF logical pages onto a single physical page). The value of this member can be one of the following:

| Value | Meaning |
| --- | --- |
| DMNUP_SYSTEM | The print system handles "N-up" printing. |
| DMNUP_ONEUP | The print system does not handle "N-up" printing. An application can set **dmNup** to DMNUP_ONEUP if it intends to carry out "N-up" printing on its own. |

This member is not used for displays.

### `dmDisplayFrequency`

For displays, specifies the frequency, in hertz, of a display device in its current mode.

This member is not used for printers.

### `dmICMMethod`

Specifies one of the DMICMMETHOD-prefixed constants defined in *wingdi.h*.

### `dmICMIntent`

Specifies one of the DMICM-prefixed constants defined in *wingdi.h*.

### `dmMediaType`

Specifies one of the DMMEDIA-prefixed constants defined in *wingdi.h*.

### `dmDitherType`

Specifies one of the DMDITHER-prefixed constants defined in *wingdi.h*.

### `dmReserved1`

Is reserved for system use and should be ignored by the driver.

### `dmReserved2`

Is reserved for system use and should be ignored by the driver.

### `dmPanningWidth`

Is reserved for system use and should be ignored by the driver.

### `dmPanningHeight`

Is reserved for system use and should be ignored by the driver.

##### - dmDisplayFlags.DM_GRAYSCALE

Specifies that the display is not a color device. If this flag is not set, color is assumed.

##### - dmDisplayFlags.DM_INTERLACED

Specifies that the display mode is interlaced. If the flag is not set, noninterlaced is assumed.

## Remarks

The [DEVMODEW structure](https://learn.microsoft.com/windows-hardware/drivers/display/the-devmodew-structure) is the Unicode version of the [DEVMODE](https://learn.microsoft.com/previous-versions//ms535771(v=vs.85))  structure (described in the Microsoft Windows SDK documentation). While applications can use either the ANSI or Unicode version of the structure, drivers are required to use the Unicode version.

For printer drivers, the DEVMODEW structure is used for specifying printer characteristics required by a print document. It is also used for specifying a printer's default characteristics.

Immediately following a DEVMODEW structure's defined members (often referred to as its public members), there can be a set of driver-defined members (often referred to as private DEVMODEW members). The driver supplies the size, in bytes, of this private area in **dmDriverExtra**. Driver-defined private members are for exclusive use by the driver. The starting address for the private members can be referenced using the **dmSize** member as follows:

```
PVOID pvDriverData = (PVOID) (((BYTE *) pdm) + (pdm->dmSize));
```

A driver can rely on the spooler to pass a DEVMODEW buffer that is no smaller than (**dmSize** + **dmDriverExtra**) bytes. As a result, the driver can safely read that number of bytes starting from the beginning of the buffer without causing an access violation, and without needing to probe memory.

Prior to playing EMF, GDI calls the spooler to validate the contents of the public portion of the DEVMODEW buffer. If the DEVMODEW buffer does not pass the validation tests performed in the spooler, GDI does not pass the buffer on to the printer driver.

**Warning** Windows only confirms that the public portion of DEVMODEW is valid. However, corrupted data in the private portion of the structure can cause driver code to crash in the application or in the spooler process. Consequently, before each use of DEVMODEW data the driver should verify that the private portion of DEVMODEW is well-formed.

In Windows 2000, a new **union** member was added to the DEVMODEW structure. This **union** member contains an existing DEVMODEW structure member, **dmDisplayFlags**, together with a new member, **dmNup**. This member is described in the preceding Members section.

In Windows XP, a new **struct** member was added. This **struct** member contains an existing DEVMODEW structure member, **dmPosition**, together with two new members, **dmDisplayOrientation** and **dmDisplayFixedOutput**. These members are described in the preceding Members section.

Also for Windows XP, several members of the DEVMODEW structure were moved to different locations in this structure. The **dmScale**, **dmCopies**, **dmDefaultSource**, and **dmPrintQuality** members were appended to the **struct** member containing the **dmOrientation**, **dmPaperSize**, **dmPaperLength**, and **dmPaperWidth** members.

> [!NOTE]
> The wingdi.h header defines DEVMODE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DOCUMENTPROPERTYHEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winddiui/ns-winddiui-_documentpropertyheader)

[DrvConvertDevMode](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winddiui/nf-winddiui-drvconvertdevmode)

[DrvDeviceCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/winddiui/nf-winddiui-drvdevicecapabilities)

[DrvGetModes](https://learn.microsoft.com/windows/win32/api/winddi/nf-winddi-drvgetmodes)