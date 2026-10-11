# LicenseProtectionStatus enumeration

The **LicenseProtectionStatus** enumeration describes the protection state of a license key that's managed through the [RegisterLicenseKeyWithExpiration](https://learn.microsoft.com/windows/win32/api/licenseprotection/nf-licenseprotection-registerlicensekeywithexpiration) and [ValidateLicenseKeyProtection](https://learn.microsoft.com/windows/win32/api/licenseprotection/nf-licenseprotection-validatelicensekeyprotection) functions.

## Syntax

```cpp
typedef enum _LicenseProtectionStatus {
  Success,
  LicenseKeyNotFound,
  LicenseKeyUnprotected,
  LicenseKeyCorrupted,
  LicenseKeyAlreadyExists
} LicenseProtectionStatus;
```

## Constants

### Success

The operation succeeded and the license key is protected.

### LicenseKeyNotFound

The specified license key wasn't found.

### LicenseKeyUnprotected

The license key exists but isn't currently protected.

### LicenseKeyCorrupted

The stored license key data is corrupted.

### LicenseKeyAlreadyExists

A license key with the same identity is already registered.

## Requirements

| Requirement | Value |
| --- | --- |
| **Minimum supported client** | Windows 10, version 20H2 [desktop apps only] |
| **Minimum supported server** | Windows Server 2025 [desktop apps only] |
| **Header** | `licenseprotection.h` |

## See also

[RegisterLicenseKeyWithExpiration](https://learn.microsoft.com/windows/win32/api/licenseprotection/nf-licenseprotection-registerlicensekeywithexpiration)

[ValidateLicenseKeyProtection](https://learn.microsoft.com/windows/win32/api/licenseprotection/nf-licenseprotection-validatelicensekeyprotection)