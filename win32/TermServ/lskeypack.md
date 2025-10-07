# LSKeyPack structure

Contains information about a specific Remote Desktop Services licensing key pack.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**dwVersion**

Version of the key pack.

**ucKeyPackType**

Type of key pack.

**szCompanyName**

Name of the company that issued the key pack.

**szKeyPackId**

ID of the key pack.

**szProductName**

Name of the product to which this key pack belongs.

**szProductId**

ID of the product to which this key pack belongs.

**szProductDesc**

Description of the product to which this key pack belongs.

**wMajorVersion**

Major version of the product to which this key pack belongs.

**wMinorVersion**

Minor version of the product to which this key pack belongs.

**dwPlatformType**

Platform type.

**ucLicenseType**

Type of licenses in the key pack.

**dwLanguageId**

Language ID.

**ucChannelOfPurchase**

Channel of purchase.

**szBeginSerialNumber**

Serial number for the first license.

**dwTotalLicenseInKeyPack**

Total number of licenses in the key pack.

**dwProductFlags**

Flags.

**dwKeyPackId**

ID of the key pack.

**ucKeyPackStatus**

Status of the key pack.

**dwActivateDate**

Activation date for the key pack.

**dwExpirationDate**

Expiration date for the key pack.

**dwNumberOfLicenses**

Number of licenses.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |

## See also

[**TLSKeyPackEnumBegin**](https://learn.microsoft.com/windows/win32/termserv/tlskeypackenumbegin)

[**TLSKeyPackEnumNext**](https://learn.microsoft.com/windows/win32/termserv/tlskeypackenumnext)

[**TLSKeyPackEnumEnd**](https://learn.microsoft.com/windows/win32/termserv/tlskeypackenumend)

