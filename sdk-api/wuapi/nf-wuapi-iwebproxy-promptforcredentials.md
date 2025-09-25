# IWebProxy::PromptForCredentials

## Description

Prompts the user for the password to use for proxy authentication.

## Parameters

### `parentWindow` [in]

The parent window of the dialog box in which the user enters the credentials.

### `title` [in]

The title to use for the dialog box in which the user enters the credentials.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## Remarks

This method can be changed only by a user on the computer. This method can be accessed through the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface.

If null is specified for the parent window (for example, if you specified Nothing in Visual Basic), the dialog box is displayed on the desktop.

## See also

[IWebProxy](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iwebproxy)