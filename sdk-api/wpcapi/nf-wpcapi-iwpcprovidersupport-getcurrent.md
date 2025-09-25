# IWPCProviderSupport::GetCurrent

## Description

Retrieves the GUID of the current provider.

## Parameters

### `pguidProvider` [out]

The GUID of the current provider.

## Return value

If the method succeeds, the method returns **S_OK**.

If the method fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *pguidProvider* parameter is not valid. |

## Remarks

The *pguidProvider* parameter will be a null GUID if there is no currently selected provider.

## See also

[IWPCProviderSupport](https://learn.microsoft.com/windows/desktop/api/wpcapi/nn-wpcapi-iwpcprovidersupport)