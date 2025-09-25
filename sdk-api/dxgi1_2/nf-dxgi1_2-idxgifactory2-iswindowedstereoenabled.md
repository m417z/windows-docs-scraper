## Description

Determines whether to use stereo mode.

## Return value

Indicates whether to use stereo mode. **TRUE** indicates that you can use stereo mode; otherwise, **FALSE**.

**Platform Update for Windows 7:** On Windows 7 or Windows Server 2008 R2 with the [Platform Update for Windows 7](https://support.microsoft.com/help/2670838) installed, **IsWindowedStereoEnabled** always returns FALSE because stereoscopic 3D display behavior isn’t available with the Platform Update for Windows 7. For more info about the Platform Update for Windows 7, see [Platform Update for Windows 7](https://learn.microsoft.com/windows/desktop/direct3darticles/platform-update-for-windows-7).

## Remarks

We recommend that windowed applications call **IsWindowedStereoEnabled** before they attempt to use stereo. **IsWindowedStereoEnabled** returns **TRUE** if both of the following items are true:

* All adapters in the computer have drivers that are capable of stereo. This only means that the driver is implemented to the Windows Display Driver Model (WDDM) for Windows 8 (WDDM 1.2). However, the adapter does not necessarily have to be able to scan out stereo.
* The current desktop mode (desktop modes are mono) and system policy and hardware are configured so that the Desktop Window Manager (DWM) performs stereo composition on at least one adapter output.

The creation of a windowed stereo swap chain succeeds if the first requirement is met. However, if the adapter can't scan out stereo, the output on that adapter is reduced to mono.

The [Direct3D 11.1 Simple Stereo 3D Sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/Direct3D%20stereoscopic%203D%20sample) shows how to add a stereoscopic 3D effect and how to respond to system stereo changes.

## See also

[IDXGIFactory2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgifactory2)