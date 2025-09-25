# IX509EnrollmentPolicyServer::GetIsDefaultCEP

## Description

The **GetIsDefaultCEP** method retrieves a Boolean value that specifies whether this is the default certificate enrollment policy (CEP) server.

## Parameters

### `pValue` [out, retval]

Pointer to a Boolean value that specifies whether this is the default server.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## Remarks

The default server is set by the [Initialize](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-icertpropertyenrollmentpolicyserver-initialize) method on the [ICertPropertyEnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-icertpropertyenrollmentpolicyserver) interface.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)