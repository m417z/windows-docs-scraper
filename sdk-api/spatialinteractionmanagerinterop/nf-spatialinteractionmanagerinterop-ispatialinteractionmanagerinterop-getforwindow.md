# ISpatialInteractionManagerInterop::GetForWindow

## Description

Retrieves a [SpatialInteractionManager](https://learn.microsoft.com/uwp/api/windows.ui.input.spatial.spatialinteractionmanager) object bound to the active application.

## Parameters

### `window` [in]

Type: [HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

Handle to the window of the active application.

### `riid` [in]

Type: **REFIID**

The GUID of the [SpatialInteractionManager](https://learn.microsoft.com/uwp/api/windows.ui.input.spatial.spatialinteractionmanager) object.

### `spatialInteractionManager` [out]

Type: **void\*\***

Address of a pointer to a [SpatialInteractionManager](https://learn.microsoft.com/uwp/api/windows.ui.input.spatial.spatialinteractionmanager) object.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This example shows how to retrieve a [SpatialInteractionManager](https://learn.microsoft.com/uwp/api/windows.ui.input.spatial.spatialinteractionmanager) by using **ISpatialInteractionManagerInterop::GetForWindow** to retrieve the **SpatialInteractionManager** for an [HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types).

```cppwinrt
// This code example depends on these headers.
// <SpatialInteractionManagerInterop.h>
// <Windows.UI.Input.Spatial.h>
// <winrt/Windows.UI.Input.Spatial.h>

// Create the window for the HolographicSpace.
hWnd = CreateWindowW(
    m_szWindowClass,
    m_szTitle,
    WS_VISIBLE,
    CW_USEDEFAULT,
    0,
    CW_USEDEFAULT,
    0,
    nullptr,
    nullptr,
    hInstance,
    nullptr);

if (!hWnd)
{
    winrt::check_hresult(E_FAIL);
}

{
    using namespace winrt::Windows::UI::Input::Spatial;
    winrt::com_ptr<ISpatialInteractionManagerInterop> spatialInteractionManagerInterop =
        winrt::get_activation_factory<SpatialInteractionManager, ISpatialInteractionManagerInterop>();

    winrt::com_ptr<ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager> spSpatialInteractionManager;
    winrt::check_hresult(spatialInteractionManagerInterop->GetForWindow(hWnd, __uuidof(ABI::Windows::UI::Input::Spatial::ISpatialInteractionManager), winrt::put_abi(spSpatialInteractionManager)));

    SpatialInteractionManager spatialInteractionManager = spSpatialInteractionManager.as<SpatialInteractionManager>();
}
```

## See also

* [ISpatialInteractionManagerInterop](https://learn.microsoft.com/windows/win32/api/spatialinteractionmanagerinterop/nn-spatialinteractionmanagerinterop-ispatialinteractionmanagerinterop)
* [SpatialInteractionManager](https://learn.microsoft.com/uwp/api/windows.ui.input.spatial.spatialinteractionmanager)
* [Mixed Reality Dev Center](https://learn.microsoft.com/windows/mixed-reality)
* [Windows.Graphics.Holographic](https://learn.microsoft.com/uwp/api/windows.graphics.holographic)