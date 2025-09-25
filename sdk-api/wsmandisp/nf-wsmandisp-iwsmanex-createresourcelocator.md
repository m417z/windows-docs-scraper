# IWSManEx::CreateResourceLocator

## Description

Creates a [ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) object that can be used instead of a resource URI in [Session](https://learn.microsoft.com/windows/desktop/WinRM/session) object operations such as [IWSManSession.Get](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-get), [IWSManSession.Put](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-put), or [Session.Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate).

## Parameters

### `strResourceLocator` [in]

The resource URI for the resource. For more information about URI strings, see [Resource URIs](https://learn.microsoft.com/windows/desktop/WinRM/resource-uris).

### `newResourceLocator` [out]

A pointer to a new instance of [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the **FragmentDialect** property is not specified in the [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object, the default is the XPath 1.0 specification. For more information, see [http://www.w3.org/TR/xpath](https://www.w3.org/TR/xpath).

## See also

[IWSManEx](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanex)

[WSMan](https://learn.microsoft.com/windows/desktop/WinRM/wsman)

[Windows Remote Management Reference](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-reference)