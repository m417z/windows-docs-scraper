# CreateXamlUIPresenter function

A static creator function that can create a [**XamlUIPresenter**](https://learn.microsoft.com/uwp/api/Windows.UI.Xaml.Hosting.XamlUIPresenter) for a render surface in a desktop app.

## Parameters

*pPresentSite* \[in\]

An existing hosting interface. See **IViewObjectPresentNotifySite** in Internet Explorer documentation.

*ppPresenter* \[out\]

The **\[exclusiveto\]** interface for a [**XamlUIPresenter**](https://learn.microsoft.com/uwp/api/Windows.UI.Xaml.Hosting.XamlUIPresenter).

## Return value

A standard **HResult**, **S\_OK** for success.

## Remarks

Calling this method requires a **DllImport** from Windows.UI.Xaml.dll.

You cannot call this method from a Windows Store app.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------------|
| Header<br> | Windows.ui.xaml-coretypes.idl |
| DLL<br> | Windows.UI.Xaml.dll |

## See also

[**XamlUIPresenter**](https://learn.microsoft.com/uwp/api/Windows.UI.Xaml.Hosting.XamlUIPresenter)

