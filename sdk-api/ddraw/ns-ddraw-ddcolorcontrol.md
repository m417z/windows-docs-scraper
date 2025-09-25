## Description

The DDCOLORCONTROL structure defines the color controls associated with a Microsoft DirectDraw [*video port extensions (VPE)*](https://learn.microsoft.com/windows-hardware/drivers/display/video-port-extensions-to-directx) object.

## Members

### `dwSize`

Specifies the size in bytes of this DDCOLORCONTROL structure.

### `dwFlags`

Indicates a set of flags that specify what structure members contain valid data. When the structure is returned by [*DdVideoPortColorControl*](https://msdn.microsoft.com/library/ff550383/(v=vs.85/)), it also indicates what options are supported by the VPE object. This member can be a bitwise OR of the values listed in the following table.

| Flag | Meaning |
| --- | --- |
| DDCOLOR_BRIGHTNESS | The **lBrightness** member contains valid data. |
| DDCOLOR_CONTRAST | The **lContrast** member contains valid data. |
| DDCOLOR_COLORENABLE | The **lColorEnable** member contains valid data. |
| DDCOLOR_GAMMA | The **lGamma** member contains valid data. |
| DDCOLOR_HUE | The **lHue** member contains valid data. |
| DDCOLOR_SATURATION | The **lSaturation** member contains valid data. |
| DDCOLOR_SHARPNESS | The **lSharpness** member contains valid data. |

### `lBrightness`

Specifies the luminance intensity (Black Level), in IRE units\*100. This member can range from 0 to 10,000, with a default value of 750 (7.5 IRE).

### `lContrast`

Specifies the relative difference between higher and lower intensity luminance values, in IRE units\*100. This member can range from 0 to 20,000, with a default value of 10,000 (100 IRE). Higher values of contrast cause darker luminance values to tend toward black, and cause lighter luminance values to tend toward white. Lower values of contrast cause all luminance values to move toward the middle luminance values.

### `lHue`

Specifies the phase relationship of the chrominance components. Hue is specified in degrees, with a valid range of -180 to 180. The default is 0 degrees.

### `lSaturation`

Specifies the color intensity, in IRE units\*100. This member can range from 0 to 20,000, with a default value of 10,000 (100 IRE).

### `lSharpness`

Specifies the sharpness in arbitrary units. The valid range is 0 to 10, with a default value of 5.

### `lGamma`

Controls the amount of gamma correction applied to the luminance values. The valid range is 1 to 500 gamma units, with a default of 1.

### `lColorEnable`

Specifies a flag indicating whether color is used. If this member is zero, color is not used; if it is 1, then color is used. The default value is 1.

### `dwReserved1`

Reserved for system use, and should be ignored.

## Remarks

## See also

* [DdVideoPortColorControl](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_vportcb_colorcontrol)