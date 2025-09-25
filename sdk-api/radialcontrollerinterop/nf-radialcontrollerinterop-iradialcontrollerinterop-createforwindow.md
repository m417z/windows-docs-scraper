# IRadialControllerInterop::CreateForWindow

## Description

Instantiates a [RadialController](https://learn.microsoft.com/uwp/api/windows.ui.input.radialcontroller) object and binds it to the active application.

## Parameters

### `hwnd` [in]

Handle to the window of the active application.

### `riid` [in]

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example, __uuidof(IRadialController) will get the GUID of the interface to a buffer resource.

### `ppv` [out]

Address of a pointer to a [RadialController](https://learn.microsoft.com/uwp/api/windows.ui.input.radialcontroller) object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

**Developer and UX guidance**

[IRadialControllerInterop](https://learn.microsoft.com/previous-versions/windows/desktop/api/radialcontrollerinterop/nn-radialcontrollerinterop-iradialcontrollerinterop)

**Samples**

[Surface Dial interactions](https://learn.microsoft.com/windows/uwp/design/input/windows-wheel-interactions)

[Universal Windows Platform samples (C# and C++)](https://github.com/Microsoft/Windows-universal-samples/tree/b78d95134ce2d57c848e0a8dc339fc362748fb9c/Samples/RadialController)

[Windows classic desktop sample](https://github.com/Microsoft/Windows-classic-samples/tree/master/Samples/RadialController)