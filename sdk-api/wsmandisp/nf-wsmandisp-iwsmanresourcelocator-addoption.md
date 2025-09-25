# IWSManResourceLocator::AddOption

## Description

Adds data required to process the request. For example, some WMI providers may require an [IWbemContext](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemcontext) or [SWbemNamedValueSet](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemnamedvalueset) object with provider-specific information. You can provide a [ResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator) object instead of specifying a resource URI in [IWSManSession](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmansession) object operations such as [Get](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-get), [Put](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-put), or [Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate).

## Parameters

### `OptionName` [in]

The name of the optional data object.

### `OptionValue` [in]

A value supplied for the optional data object.

### `mustComply` [in]

A flag that indicates the option must be processed. The default is **False** (0).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWSManResourceLocator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanresourcelocator)

[ResourceLocator.AddOption](https://learn.microsoft.com/windows/desktop/WinRM/resourcelocator-addoption)