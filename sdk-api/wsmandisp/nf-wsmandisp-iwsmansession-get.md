# IWSManSession::Get

## Description

Retrieves the resource specified by the [URI](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) and returns an XML representation of the current instance of the resource.

## Parameters

### `resourceUri` [in]

The identifier of the resource to be retrieved.

This parameter can contain one of the following:

* URI with or without [selectors](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary). When calling the [Get](https://learn.microsoft.com/windows/desktop/WinRM/session-get) method to obtain a WMI resource, use the key property or properties of the object.
* [ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) object which may contain selectors, [fragments](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary), or [options](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary).
* [WS-Addressing](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) endpoint reference as described in the WS-Management protocol standard. For more information about the public specification for the WS-Management protocol, see [Management Specifications Index Page](https://learn.microsoft.com/previous-versions/dotnet/articles/ms951267(v=msdn.10)).

### `flags` [in]

Reserved for future use. Must be set to 0.

### `resource` [out]

A value that, upon success, is an XML representation of the resource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.Get](https://learn.microsoft.com/windows/desktop/WinRM/session-get)