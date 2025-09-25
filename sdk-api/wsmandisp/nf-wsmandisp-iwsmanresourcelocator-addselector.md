# IWSManResourceLocator::AddSelector

## Description

Adds a [selector](https://learn.microsoft.com/windows/desktop/WinRM/windows-remote-management-glossary) to the [ResourceLocator](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator) object. The selector specifies a particular instance of a *resource*. You can provide an [IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object instead of specifying a resource URI in [IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession) object operations such as [Get](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-get), [Put](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-put), or [Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate).

## Parameters

### `resourceSelName` [in]

The selector name. For example, when requesting WMI data, this parameter is the key property for a WMI class.

### `selValue` [in]

The selector value. For example, for WMI data, this parameter contains a value for a key property that identifies a specific instance.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator)

[ResourceLocator.AddSelector](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator-addselector)