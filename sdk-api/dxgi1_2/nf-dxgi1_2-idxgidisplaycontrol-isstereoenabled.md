# IDXGIDisplayControl::IsStereoEnabled

## Description

Retrieves a Boolean value that indicates whether the operating system's stereoscopic 3D display behavior is enabled.

## Return value

**IsStereoEnabled** returns TRUE when the operating system's stereoscopic 3D display behavior is enabled and FALSE when this behavior is disabled.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **IsStereoEnabled** always returns FALSE because stereoscopic 3D display behavior isn’t available with the Platform Update for Windows 7. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

You pass a Boolean value to the [IDXGIDisplayControl::SetStereoEnabled](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nf-dxgi1_2-idxgidisplaycontrol-setstereoenabled) method to either enable or disable the operating system's stereoscopic 3D display behavior. TRUE enables the operating system's stereoscopic 3D display behavior and FALSE disables it.

## See also

[IDXGIDisplayControl](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgidisplaycontrol)