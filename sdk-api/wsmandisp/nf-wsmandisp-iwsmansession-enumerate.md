# IWSManSession::Enumerate

## Description

Enumerates a table, data collection, or log resource. To create a query, include a *filter* parameter and a *dialect* parameter in an enumeration. You can also use an [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object to create queries. For more information, see [Enumerating or Listing All the Instances of a Resource](https://learn.microsoft.com/windows/desktop/WinRM/enumerating-or-listing-all-instances-of-a-resource).

## Parameters

### `resourceUri` [in]

The identifier of the resource to be retrieved.

The following list contains identifiers that this parameter can contain:

* URI with one or more [selectors](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary). When calling the **Enumerate** method to obtain a WMI resource, use the key property or properties of the object.
* You can use [selectors](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary), [fragments](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary), or [options](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary). For more information, see [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator).
* [WS-Addressing](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) endpoint reference as described in the WS-Management protocol standard. For more information about the public specification for the WS-Management protocol, see the [Management Specifications Index Page](https://learn.microsoft.com/previous-versions/dotnet/articles/ms951267(v=msdn.10)).

### `filter` [in, optional]

A filter that defines what items in the resource are returned by the enumeration. When the resource is enumerated, only those items that match the filter criteria are returned. Including a *filter* parameter and a *dialect* parameter in an enumeration converts the enumeration into a query.

If you have an [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object for the *resourceURI* parameter, then this parameter should not be used. Instead, use the selector and fragment functionality of **IWSManResourceLocator**.

### `dialect` [in, optional]

The language used by the filter. [WQL](https://learn.microsoft.com/windows/desktop/WmiSdk/wql-sql-for-wmi), a subset of SQL used by WMI, is the only language supported.

If you have a [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object for the *resourceURI* parameter, then this parameter should not be used. Instead, use the selector and fragment functionality of **IWSManResourceLocator**.

### `flags` [in]

This parameter must contain a flag in the **__WSManEnumFlags** enumeration. For more information, see [Enumeration Constants](https://learn.microsoft.com/windows/desktop/WinRM/enumeration-constants).

### `resultSet` [out]

An [IWSManEnumerator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanenumerator) object that contains the results of the enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call **IWSManSession::Enumerate** to start an enumeration operation. Thereafter, call [IWSManEnumerator::ReadItem](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmanenumerator-readitem) using the returned [IWSManEnumerator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanenumerator) object until the end of items is indicated by the [AtEndOfStream](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmanenumerator-get_atendofstream) property.

Be aware that if the flags include the [Enumeration Constants](https://learn.microsoft.com/windows/desktop/WinRM/enumeration-constants) **WSManFlagHierarchyDeepBasePropsOnly** or **WSManFlagHierarchyShallow** then Windows Remote Management service returns the error code **ERROR_WSMAN_POLYMORPHISM_MODE_UNSUPPORTED**.

For more information about limiting network calls during an enumeration, see the [BatchItems](https://learn.microsoft.com/windows/desktop/WinRM/session-batchitems) property.

If a filter is specified, it must be a valid document with respect to the schema of the resource. The dialect parameter is optional. However, if the filter string begins with <, but is not an XML fragment, then either include the *dialect* parameter or set the **WSManFlagNonXmlText** flag in the *flags* parameter. For more information, see [Enumeration Constants](https://learn.microsoft.com/windows/desktop/WinRM/enumeration-constants).

The corresponding scripting method is [Session.Enumerate](https://learn.microsoft.com/windows/desktop/WinRM/session-enumerate).

## See also

[IWSManEnumerator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanenumerator)

[IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession)

[Session.Enumerate](https://learn.microsoft.com/windows/desktop/WinRM/session-enumerate)