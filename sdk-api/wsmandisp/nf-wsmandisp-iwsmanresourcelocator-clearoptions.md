# IWSManResourceLocator::ClearOptions

## Description

Removes any [options](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) from the [ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) object. You can provide a [ResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object instead of specifying a resource URI in [IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession) object operations such as [Get](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-get), [Put](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-put), or [Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator)

[ResourceLocator.ClearOptions](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator-clearoptions)