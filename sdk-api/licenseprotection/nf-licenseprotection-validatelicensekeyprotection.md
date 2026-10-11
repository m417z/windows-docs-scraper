# ValidateLicenseKeyProtection function

Validates a license key that was previously registered and returns when it is valid and its protection status.

## Syntax

```cpp
HRESULT ValidateLicenseKeyProtection(
  [in]  PCWSTR                   licenseKey,
  [out] PFILETIME                notValidBefore,
  [out] PFILETIME                notValidAfter,
  [out] LicenseProtectionStatus *status
);
```

## Parameters

*licenseKey* `[in]`

A pointer to a null-terminated wide-character string that specifies the license key to validate.

*notValidBefore* `[out]`

A pointer to a `FILETIME` structure that receives the date and time before which the license key isn't valid.

*notValidAfter* `[out]`

A pointer to a `FILETIME` structure that receives the date and time after which the license key isn't valid.

*status* `[out]`

A pointer to a [LicenseProtectionStatus](https://learn.microsoft.com/windows/win32/api/licenseprotection/ne-licenseprotection-licenseprotectionstatus) value that receives the protection status of the license key.

## Return value

Returns `S_OK` if the function succeeds. Otherwise, it returns an `HRESULT` error code.

| Return code | Description |
| --- | --- |
| `S_OK` | The function succeeded. |
| `E_INVALIDARG` | One or more of the parameters is `NULL`. |

## Remarks

Use ValidateLicenseKeyProtection to check the license protection status of a registered license key.

## Requirements

| Requirement | Value |
| --- | --- |
| **Minimum supported client** | Windows 11, version 21H2 [desktop apps only] |
| **Minimum supported server** | Windows Server 2025 [desktop apps only] |
| **Header** | `licenseprotection.h` |
| **Library** | `api-ms-win-security-licenseprotection-l1-1-0.lib` |
| **DLL** | `Licenseprotection.dll`; `api-ms-win-security-licenseprotection-l1` |

## See also

[RegisterLicenseKeyWithExpiration](https://learn.microsoft.com/windows/win32/api/licenseprotection/nf-licenseprotection-registerlicensekeywithexpiration)

[LicenseProtectionStatus](https://learn.microsoft.com/windows/win32/api/licenseprotection/ne-licenseprotection-licenseprotectionstatus)