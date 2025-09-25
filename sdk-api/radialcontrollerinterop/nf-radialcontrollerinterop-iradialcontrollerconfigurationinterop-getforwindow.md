# IRadialControllerConfigurationInterop::GetForWindow

## Description

Retrieves a [RadialControllerConfiguration](https://learn.microsoft.com/uwp/api/windows.ui.input.radialcontrollerconfiguration) object bound to the active application.

## Parameters

### `hwnd` [in]

Handle to the window of the active application.

### `riid` [in]

The GUID of the [RadialControllerConfiguration](https://learn.microsoft.com/uwp/api/windows.ui.input.radialcontrollerconfiguration) object.

### `ppv` [out]

Address of a pointer to a [RadialControllerConfiguration](https://learn.microsoft.com/uwp/api/windows.ui.input.radialcontrollerconfiguration) object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Developer and UX guidance**

[IRadialControllerConfigurationInterop](https://learn.microsoft.com/previous-versions/windows/desktop/api/radialcontrollerinterop/nn-radialcontrollerinterop-iradialcontrollerconfigurationinterop)

**Samples**

[Surface Dial interactions](https://learn.microsoft.com/windows/uwp/design/input/windows-wheel-interactions)

[Universal Windows Platform samples (C# and C++)](https://github.com/Microsoft/Windows-universal-samples/tree/b78d95134ce2d57c848e0a8dc339fc362748fb9c/Samples/RadialController)

[Windows classic desktop sample](https://github.com/Microsoft/Windows-classic-samples/tree/master/Samples/RadialController)