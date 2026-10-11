# RegisterLicenseKeyWithExpiration function

Registers a license key and associates an expiration date with it.

## Syntax

```cpp
HRESULT RegisterLicenseKeyWithExpiration(
  [in]  PCWSTR                   licenseKey,
  [in]  UINT32                   validityInDays,
  [out] LicenseProtectionStatus *status
);
```

## Parameters

*licenseKey* `[in]`

A pointer to a null-terminated wide-character string that specifies the license key to register.

*validityInDays* `[in]`

Specifies the validity period, in days, of the license key.

*status* `[out]`

A pointer to a [LicenseProtectionStatus](https://learn.microsoft.com/windows/win32/api/licenseprotection/ne-licenseprotection-licenseprotectionstatus) value that receives the protection status of the license key.

## Return value

Returns `S_OK` if the function succeeds. Otherwise, it returns an `HRESULT` error code.

| Return code | Description |
| --- | --- |
| `S_OK` | The function succeeded. |
| `E_INVALIDARG` | The *validityInDays* parameter is invalid, or the *status* parameter is `NULL`. |

## Remarks

Use the License Protection APIs to register a license key with an associated expiration date, and later return the status of a previously registered key.

## Requirements

| Requirement | Value |
| --- | --- |
| **Minimum supported client** | Windows 11, version 21H2 [desktop apps only] |
| **Minimum supported server** | Windows Server 2025 [desktop apps only] |
| **Header** | `licenseprotection.h` |
| **Library** | `api-ms-win-security-licenseprotection-l1-1-0.lib` |
| **DLL** | `Licenseprotection.dll`; `api-ms-win-security-licenseprotection-l1` |

## See also

[ValidateLicenseKeyProtection](https://learn.microsoft.com/windows/win32/api/licenseprotection/nf-licenseprotection-validatelicensekeyprotection)

[LicenseProtectionStatus](https://learn.microsoft.com/windows/win32/api/licenseprotection/ne-licenseprotection-licenseprotectionstatus)