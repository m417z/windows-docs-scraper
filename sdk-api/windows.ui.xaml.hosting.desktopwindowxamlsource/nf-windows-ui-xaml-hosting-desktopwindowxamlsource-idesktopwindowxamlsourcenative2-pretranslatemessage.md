## Description

Enables the WinRT XAML framework to process a Windows message for a [DesktopWindowXamlSource](https://learn.microsoft.com/uwp/api/windows.ui.xaml.hosting.desktopwindowxamlsource) object that hosts a WinRT XAML control.

## Parameters

### `message`

Type: **const [MSG](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-msg)\***

The Windows message to process.

### `result`

Type: **BOOL\***

True if the message was processed; otherwise, false.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code.

## Remarks

For a code example that demonstrates how to use this method, see [XamlBridge.cpp](https://github.com/microsoft/Xaml-Islands-Samples/blob/master/Samples/Win32/SampleCppApp/XamlBridge.cpp) in the SampleCppApp sample in the XAML Island samples repo.

## See also

[Using the UWP XAML hosting API in a C++ desktop (Win32) app](https://learn.microsoft.com/windows/apps/desktop/modernize/using-the-xaml-hosting-api)