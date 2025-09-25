## Description

Asynchronously requests a token from a web account provider. If necessary, the user is prompted to enter their credentials.

## Parameters

### `appWindow`

Type: **[HWND](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The window to be used as the owner for the window prompting the user for credentials, in case such a window becomes necessary.

### `request`

Type: **[IInspectable](https://learn.microsoft.com/windows/win32/api/inspectable/nn-inspectable-iinspectable)\***

The web token request, given as an instance of the
[WebTokenRequest](https://learn.microsoft.com/uwp/api/windows.security.authentication.web.core.webtokenrequest)
class type-casted to the [IInspectable](https://learn.microsoft.com/windows/win32/api/inspectable/nn-inspectable-iinspectable)
interface.

### `riid`

Type: **REFIID**

Must be a reference to the [interface identifier (IID)](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/5583e1b8-454c-4147-9f56-f72416a15bee#gt_76ad3105-3f05-479d-a40c-c9c8fa2ebd83) for the interface
[IAsyncOperation](https://learn.microsoft.com/uwp/api/windows.foundation.iasyncoperation-1)\<[WebTokenRequestResult](https://learn.microsoft.com/uwp/api/windows.security.authentication.web.core.webtokenrequestresult)\>.
This IID is automatically generated, and you can obtain it using code like this:

```cppwinrt
using winrt::Windows::Foundation::IAsyncOperation;
using winrt::Windows::Security::Authentication::Web::Core::WebTokenRequestResult;

constexpr winrt::guid iidAsyncRequestResult{ winrt::guid_of<IAsyncOperation<WebTokenRequestResult>>() };
```

### `asyncInfo`

Type: **void\*\***

The address of a pointer to [IAsyncOperation](https://learn.microsoft.com/uwp/api/windows.foundation.iasyncoperation-1)\<[WebTokenRequestResult](https://learn.microsoft.com/uwp/api/windows.security.authentication.web.core.webtokenrequestresult)\>. On successful return from this method, the pointer will be set to the asynchronous request operation object for the request operation just started.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

A status code for the attempt to start the asynchronous request operation.

## Remarks

This method is the equivalent for desktop apps of
[WebAuthenticationCoreManager.RequestTokenAsync(WebTokenRequest)](https://learn.microsoft.com/uwp/api/windows.security.authentication.web.core.webauthenticationcoremanager.requesttokenasync#Windows_Security_Authentication_Web_Core_WebAuthenticationCoreManager_RequestTokenAsync_Windows_Security_Authentication_Web_Core_WebTokenRequest_).

## See also

- [Web account management sample app](https://github.com/Microsoft/Windows-universal-samples/tree/master/Samples/WebAccountManagement)
- [RequestTokenWithWebAccountForWindowAsync](https://learn.microsoft.com/windows/win32/api/webauthenticationcoremanagerinterop/nf-webauthenticationcoremanagerinterop-iwebauthenticationcoremanagerinterop-requesttokenwithwebaccountforwindowasync)