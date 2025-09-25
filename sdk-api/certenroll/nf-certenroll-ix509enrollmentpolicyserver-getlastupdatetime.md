# IX509EnrollmentPolicyServer::GetLastUpdateTime

## Description

The **GetLastUpdateTime** method retrieves the date and time at which the policy was last downloaded.

## Parameters

### `pDate` [out, retval]

Pointer to a **DATE** value that identifies the time.

## Return value

If the function succeeds, the function returns **S_OK**.

If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **CERTSRV_E_PROPERTY_EMPTY** | The value could not be found. |
| **E_POINTER** | The *pDate* parameter cannot be **NULL**. |

## Remarks

The date is stored as an 8-byte real value that represents a Coordinated Universal Time (Greenwich Mean Time) value between January 1, 1900 and December 31, 9999, inclusive. The value 2.0 represents January 1, 1900; 3.0 represents January 2, 1900. Adding 1 to the value increments the date by a day. The fractional part of the value represents the time of day. Therefore, 2.5 represents 12:00 on January 1, 1900; 3.25 represents 06:00 on January 2, 1900.

## See also

[IX509EnrollmentPolicyServer](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509enrollmentpolicyserver)