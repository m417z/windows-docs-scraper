## Description

Gets the [ShareWindowCommandSource](https://learn.microsoft.com/uwp/api/windows.ui.shell.sharewindowcommandsource) object corresponding to a window identifier (a window handle).

The window identifier represents the window where the call or meeting is established. This allows the Windows Shell to use the window identifier to obtain resources such as an icon, and to provide that as a hint to the user.

> [!IMPORTANT]
> The **IShareWindowCommandSourceInterop::GetForWindow** API is part of a Limited Access Feature (see [LimitedAccessFeatures class](https://learn.microsoft.com/uwp/api/windows.applicationmodel.limitedaccessfeatures)). For more information or to request an unlock token, contact [Microsoft Support](https://aka.ms/LAFAccessRequests).

## Parameters

### `appWindow`

Type: **[HWND](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

The window identifier (a window handle) of the window where the call or meeting is established.

The window identified by the HWND passed in *appWindow* must be such that it is capable of providing the brand icon, and the friendly name, of the client application.

### `riid`

Type: **[REFIID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/bbde795f-5398-42d8-9f59-3613da03c318)**

A reference to the interface identifier of the **Windows::UI::Shell::IShareWindowCommandSource** interface.

### `shareWindowCommandSource`

Type: **[void](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\*\***

The address of a **Windows::UI::Shell::IShareWindowCommandSource** pointer in which to receive the [ShareWindowCommandSource](https://learn.microsoft.com/uwp/api/windows.ui.shell.sharewindowcommandsource) object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

For a code example, see [IShareWindowCommandSourceInterop](https://learn.microsoft.com/windows/win32/api/sharewindowcommandsourceinterop/nn-sharewindowcommandsourceinterop-isharewindowcommandsourceinterop).

## See also

* [IShareWindowCommandSourceInterop](https://learn.microsoft.com/windows/win32/api/sharewindowcommandsourceinterop/nn-sharewindowcommandsourceinterop-isharewindowcommandsourceinterop)

* [ShareWindowCommandSource](https://learn.microsoft.com/uwp/api/windows.ui.shell.sharewindowcommandsource)