# IX509PolicyServerUrl::SetStringProperty

## Description

The **SetStringProperty** method specifies the certificate enrollment policy (CEP) server ID or the display name of the CEP server.

## Parameters

### `propertyId` [in]

A [PolicyServerUrlPropertyID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlpropertyid) value that specifies the string to set. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PsPolicyID** | Set an ID string for the policy server. The string can be any value, but it should be unique. |
| **PsFriendlyName** | Set a display name for the policy server. |

### `pValue` [in]

A **BSTR** variable that receives the property value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The *pValue* parameter cannot be **NULL** or empty. |
| **E_OUTOFMEMORY** | Memory could not be allocated for the property value. |

## See also

[IX509PolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverurl)