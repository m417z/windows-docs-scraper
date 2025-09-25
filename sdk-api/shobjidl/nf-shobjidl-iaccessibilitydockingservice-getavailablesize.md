# IAccessibilityDockingService::GetAvailableSize

## Description

Retrieves the dimensions available on a specific screen for displaying an accessibility window.

## Parameters

### `hMonitor` [in]

Type: **HMONITOR**

The handle of the monitor whose available docking size is to be retrieved. For information on how to retrieve an **HMONITOR**, see [MonitorFromWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromwindow).

### `pcxFixed` [out]

Type: **UINT***

When this method returns successfully, this parameter receives the fixed width, in physical pixels, available for docking on the specified monitor. Any window docked to this monitor will be sized to this width.

If the method fails, this value is set to 0.

If this value is **NULL**, an access violation will occur.

### `pcyMax` [out]

Type: **UINT***

When this method returns successfully, this parameter receives the maximum height, in physical pixels, available for a docked window on the specified monitor.

If the method fails, this value is set to 0.

If this value is **NULL**, an access violation will occur.

## Return value

Type: **HRESULT**

Returns a standard return value, including the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_MONITOR_HANDLE)** | The monitor specified by *hMonitor* does not support docking. |

## Remarks

### When to use

A docked accessibility window is limited in the amount of space that it can use on any screen. Therefore, before trying to dock an accessibility window, call this function to get the available dimensions. You cannot dock any window that would cause a Windows Store app to have access to less than 768 vertical screen pixels.

#### Examples

This example shows this method in use.

```

 IAccessibilityDockingService *pDockingService;

 HRESULT hr = CoCreateInstance(CLSID_AccessibilityDockingService, CLSCTX_INPROV_SERVER, nullptr, IID_PPV_ARGS(&pDockingService));
 if (SUCCEEDED(hr))
 {
     UINT uMaxHeight;
     UINT uFixedWidth;

     HMONITOR hMonitor = MonitorFromWindow(_hwndMyApplication, MONITOR_DEFAULTTONULL);
     if (hMonitor != nullptr)
     {
         hr = pDockingService->GetAvailableSize(hMonitor, &uMaxHeight, &uFixedWidth);
     }
 }
```

## See also

[IAccessibilityDockingService](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh448546(v=vs.85))