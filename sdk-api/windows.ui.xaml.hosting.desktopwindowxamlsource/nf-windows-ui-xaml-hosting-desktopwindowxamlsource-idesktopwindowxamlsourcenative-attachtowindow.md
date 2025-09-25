## Description

Attaches the current [IDesktopWindowXamlSourceNative](https://learn.microsoft.com/windows/win32/api/windows.ui.xaml.hosting.desktopwindowxamlsource/nn-windows-ui-xaml-hosting-desktopwindowxamlsource-idesktopwindowxamlsourcenative) instance to a parent UI element in your desktop app that is associated with a window handle.

## Parameters

### `parentWnd`

Type: **HWND**

The window handle of the parent UI element in which you want to host a WinRT XAML control.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a code example that demonstrates how to use this method, see [XamlBridge.cpp](https://github.com/microsoft/Xaml-Islands-Samples/blob/master/Samples/Win32/SampleCppApp/XamlBridge.cpp) in the SampleCppApp sample in the XAML Island samples repo.

> [!IMPORTANT]
> Make sure that your code calls the **AttachToWindow** method only once per [DesktopWindowXamlSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.hosting.desktopwindowxamlsource) object. Calling this method more than once for a **DesktopWindowXamlSource** object could result in a memory leak.

## See also

[Using the UWP XAML hosting API in a C++ desktop (Win32) app](https://learn.microsoft.com/windows/apps/desktop/modernize/using-the-xaml-hosting-api)