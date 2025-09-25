## Description

Describes an output or physical connection between the adapter (video card) and a device, including additional information about color capabilities and connection type.

## Members

### `DeviceName`

Type: **WCHAR[32]**

A string that contains the name of the output device.

### `DesktopCoordinates`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)**

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the bounds of the output in desktop coordinates. Desktop coordinates depend on the dots per inch (DPI) of the desktop.
For info about writing DPI-aware Win32 apps, see [High DPI](https://learn.microsoft.com/windows/desktop/hidpi/high-dpi-desktop-application-development-on-windows).

### `AttachedToDesktop`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

True if the output is attached to the desktop; otherwise, false.

### `Rotation`

Type: **[DXGI_MODE_ROTATION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173065(v=vs.85))**

A member of the [DXGI_MODE_ROTATION](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173065(v=vs.85)) enumerated type describing on how an image is rotated by the output.

### `Monitor`

Type: **[HMONITOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An [HMONITOR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) handle that represents the display monitor. For more information, see [HMONITOR and the Device Context](https://learn.microsoft.com/windows/desktop/gdi/hmonitor-and-the-device-context).

### `BitsPerColor`

Type: **UINT**

The number of bits per color channel for the active wire format of the display attached to this output.

### `ColorSpace`

Type: **[DXGI_COLOR_SPACE_TYPE](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ne-dxgicommon-dxgi_color_space_type)**

The current advanced color capabilities of the display attached to this output. Specifically, whether it's capable of reproducing color and luminance values outside of the sRGB color space. A value of **DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709** indicates that the display is limited to SDR/sRGB. A value of **DXGI_COLOR_SPACE_RGB_FULL_G2084_NONE_P2020** indicates that the display supports advanced color capabilities. **DXGI_COLOR_SPACE_RGB_FULL_G10_NONE_P709** is currently not a color space that displays use; it's simply an intermediary swap-chain color space.

For detailed luminance and color capabilities, see additional members of this struct.

### `RedPrimary`

Type: **FLOAT[2]**

The red color primary, in xy coordinates, of the display attached to this output. This value will usually come from the EDID of the corresponding display or sometimes from an override.

### `GreenPrimary`

Type: **FLOAT[2]**

The green color primary, in xy coordinates, of the display attached to this output. This value will usually come from the EDID of the corresponding display or sometimes from an override.

### `BluePrimary`

Type: **FLOAT[2]**

The blue color primary, in xy coordinates, of the display attached to this output. This value will usually come from the EDID of the corresponding display or sometimes from an override.

### `WhitePoint`

Type: **FLOAT[2]**

The white point, in xy coordinates, of the display attached to this output. This value will usually come from the EDID of the corresponding display or sometimes from an override.

### `MinLuminance`

Type: **FLOAT**

The minimum luminance, in nits, that the display attached to this output is capable of rendering. Content should not exceed this minimum value for optimal rendering. This value will
usually come from the EDID of the corresponding display or sometimes from an override.

### `MaxLuminance`

Type: **FLOAT**

The maximum luminance, in nits, that the display attached to this output is capable of rendering; this value is likely only valid for a small area of the panel. Content should not exceed
this minimum value for optimal rendering. This value will usually come from the EDID of the corresponding display or sometimes from an override.

### `MaxFullFrameLuminance`

Type: **FLOAT**

The maximum luminance, in nits, that the display attached to this output is capable of rendering; unlike MaxLuminance, this value is valid for a color that fills the entire area of the
panel. Content should not exceed this value across the entire panel for optimal rendering. This value will usually come from the EDID of the corresponding display or sometimes from an
override.

## Remarks

The **DXGI_OUTPUT_DESC1** structure is initialized by the [IDXGIOutput6::GetDesc1](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgioutput6-getdesc1) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)