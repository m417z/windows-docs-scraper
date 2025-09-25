# WinBioGetEnrolledFactors function

## Description

Gets information about the biometric enrollments that the specified user has on the computer. Biometric enrollments include enrollments for facial recognition, fingerprint scanning, iris scanning, and so on.

## Parameters

### `AccountOwner` [in]

A [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure for the user whose biometric enrollments you want to get. For example:

``` syntax
WINBIO_IDENTITY identity = {};
identity.Type = WINBIO_ID_TYPE_SID;

// Move an account SID into identity.Value.AccountSid.Data.
// For example, CopySid(...)
```

To see the enrollments for every user on the computer, specify the **WINBIO_ID_TYPE_WILDCARD** identity type for the [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that you specify for the *AccountOwner* parameter. For example:

``` syntax
WINBIO_IDENTITY identity = {};
identity.Type = WINBIO_ID_TYPE_WILDCARD;

```

### `EnrolledFactors` [out]

A set of [WINBIO_BIOMETRIC_TYPE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-biometric-type-constants) flags that indicate the biometric enrollments that the specified user has on the computer. A value of 0 indicates that the user has no biometric enrollments.

These enrollments represent system pool enrollments only, such as enrollments that you can use to authenticate a user for sign-in, unlock, and so on. This value does not include private pool enrollments.

If you specify the wildcard identity type for the [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that you use for the *AccountOwner* parameter, this set of flags represents the combined set of enrollments for all users with accounts on the computer.

## Return value

If the function succeeds, it returns **S_OK**. If the function fails, it returns an **HRESULT** value that indicates the error. Possible values include, but are not limited to, those in the following table. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

| Return code | Description |
| --- | --- |
| **E_POINTER** | The *AccountOwner* and *EnrolledFactors* parameters cannot be **NULL**. |
| **E_INVALIDARG** | The **Type** member of the [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that the *AccountOnwer* parameter specified was not **WINBIO_ID_TYPE_SID** or **WINBIO_ID_TYPE_WILDCARD**, or the **AccountSid** member of the **WINBIO_IDENTITY** structure was not valid. |

## Remarks

**WinBioGetEnrolledFactors** does not require a biometric session handle and does not activate the biometric service. Consequently, **WinBioGetEnrolledFactors** runs quickly and is useful when your code needs to make quick decisions about how to proceed when time is critical for the set of operations you need to perform.

**WinBioGetEnrolledFactors** provides credential providers with a way to tailor their UI appropriately. For example, the login screen calls **WinBioGetEnrolledFactors** to determine whether to display the option to login with a fingerprint.

#### Examples

``` syntax
WINBIO_BIOMETRIC_TYPE enrolledFactors = WINBIO_NO_TYPE_AVAILABLE;

WINBIO_IDENTITY identity = {};
identity.Type = WINBIO_ID_TYPE_SID;

// Move an account SID into identity.Value.AccountSid.Data.
// e.g., CopySid(...)

HRESULT hr = WinBioGetEnrolledFactors(&identity, &enrolledFactors);

```

## See also

[WINBIO_BIOMETRIC_TYPE](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-biometric-type-constants)

[WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity)