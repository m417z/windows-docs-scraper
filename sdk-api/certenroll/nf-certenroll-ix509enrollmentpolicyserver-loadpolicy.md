# IX509EnrollmentPolicyServer::LoadPolicy

## Description

The **LoadPolicy** method retrieves policy information from the certificate enrollment policy (CEP) server.

## Parameters

### `option` [in]

A value of the [X509EnrollmentPolicyLoadOption](https://learn.microsoft.com/windows/desktop/api/certenroll/ne-certenroll-x509enrollmentpolicyloadoption) enumeration that specifies how to retrieve policy from the policy server. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **LoadOptionDefault** | Reload if the cache has expired. |
| **LoadOptionCacheOnly** | Always load from the cache even if it has expired. This option is not currently supported. |
| **LoadOptionReload** | Always reload. |
| **LoadOptionRegisterForADChanges** | Registers a thread to update a sequence number if there are changes to the template or the certification authority container. This value applies only to an Active Directory policy server. |

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The load option requested in the *option* parameter does not match any supported by the CEP server or you specified LoadOptionCacheOnly in the *option* parameter. |
| **E_NOT_VALID_STATE** | There was a problem with the lightweight directory access protocol (LDAP) used to locate the CEP server. |

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)