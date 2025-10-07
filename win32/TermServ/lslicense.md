# LSLicense structure

Contains information about a specific Remote Desktop Services license.

> [!Note]
> This structure is not defined in any header file. To use this structure, you must define it yourself as shown in this topic.

## Members

**dwVersion**

Version of the license.

**dwLicenseId**

ID of the license.

**dwKeyPackId**

ID of the [**LSKeyPack**](https://learn.microsoft.com/windows/win32/termserv/lskeypack) that contains the license.

**szHWID**

Hardware ID of the Remote Desktop Connection (RDC) client that was issued the license.

**szMachineName**

Name of the Remote Desktop Connection (RDC) client that was issued the license.

**szUserName**

Name of the user who was issued the license.

**dwCertSerialLicense**

Reserved for future use.

**dwLicenseSerialNumber**

Serial number of the license.

**ftIssueDate**

Date that the license was issued.

**ftExpireDate**

Date that the license will expire.

**ucLicenseStatus**

Current status of the license.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |

## See also

[**LSKeyPack**](https://learn.microsoft.com/windows/win32/termserv/lskeypack)

[**TLSLicenseEnumBegin**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumbegin)

[**TLSLicenseEnumNext**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumnext)

[**TLSLicenseEnumEnd**](https://learn.microsoft.com/windows/win32/termserv/tlslicenseenumend)

