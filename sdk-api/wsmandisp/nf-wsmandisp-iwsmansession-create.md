# IWSManSession::Create

## Description

Creates a new instance of a resource and returns the [endpoint reference](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) (EPR) of the new object.

## Parameters

### `resourceUri` [in]

The identifier of the resource to create.

This parameter can contain one of the following:

* URI with one or more [selectors](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary). Be aware that the [WMI plug-in](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) does not support creating any resource other than a WS-Management protocol listener.
* [ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) object which may contain selectors, [fragments](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary), or [options](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary).
* [WS-Addressing](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) endpoint reference as described in the WS-Management protocol standard. For more information about the public specification for the WS-Management protocol, see [Management Specifications Index Page](https://learn.microsoft.com/previous-versions/dotnet/articles/ms951267(v=msdn.10)).

### `resource` [in]

An XML string that contains resource content.

### `flags` [in]

Reserved. Must be set to 0.

### `newUri` [out]

The EPR of the new resource.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IWSManSession::Create** is only used for creating new
instances of a resource. Use the [IWSManSession::Put](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-put) method to
update existing instances of a resource. After you obtain the new resource URI, you can call
[IWSManSession::Get](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-get) to retrieve the new object. The new object
contains any properties that the resource provider assigns when creating the new object. For example, if you
create a new WS-Management protocol[listener](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) and retrieve the listener object using [Session.Get](https://learn.microsoft.com/windows/desktop/WinRM/session-get), then you also obtain the **Port**, **Enabled**, and **ListeningOn** properties.

## See also

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.Create](https://learn.microsoft.com/windows/desktop/WinRM/session-create)