# DXGI_OUTPUT_DESC structure

## Description

Describes an output or physical connection between the adapter (video card) and a device.

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

## Remarks

The **DXGI_OUTPUT_DESC** structure is initialized by the [IDXGIOutput::GetDesc](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-getdesc) method.

## See also

[DXGI Structures](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-structures)