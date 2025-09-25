# IX509PolicyServerUrl::GetStringProperty

## Description

The **GetStringProperty** method retrieves the certificate enrollment policy (CEP) server ID or the display name of the CEP server.

## Parameters

### `propertyId` [in]

A [PolicyServerUrlPropertyID](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-policyserverurlpropertyid) value that specifies the string to retrieve. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PsPolicyID** | Retrieve an ID string for the policy server. |
| **PsFriendlyName** | Retrieve a display name for the policy server. |

### `ppValue` [out, retval]

Pointer to a **BSTR** variable that receives the property value.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The property value cannot be found. |
| **E_POINTER** | The *propertyId* parameter cannot be **NULL**. |
| **E_OUTOFMEMORY** | Memory could not be allocated for the return value. |

## See also

[IX509PolicyServerUrl](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509policyserverurl)