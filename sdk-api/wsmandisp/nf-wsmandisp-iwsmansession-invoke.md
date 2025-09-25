# IWSManSession::Invoke

## Description

Invokes a method and returns the results of the method call.

## Parameters

### `actionUri` [in]

The URI of the method to invoke.

### `resourceUri` [in]

The identifier of the resource to invoke a method.

This parameter can contain one of the following:

* URI with or without [selectors](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary).
* [ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) object which may contain selectors, [fragments](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary), or [options](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary).
* [WS-Addressing](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) endpoint reference as described in the WS-Management protocol standard. For more information about the public specification for the WS-Management protocol, see [Management Specifications Index Page](https://learn.microsoft.com/previous-versions/dotnet/articles/ms951267(v=msdn.10)).

### `parameters` [in]

An XML representation of the input for the method. This string must be supplied or this method will fail.

### `flags` [in, optional]

Reserved for future use. Must be set to 0.

### `result` [out]

An XML representation of the method output.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.Invoke](https://learn.microsoft.com/windows/desktop/WinRM/session-invoke)