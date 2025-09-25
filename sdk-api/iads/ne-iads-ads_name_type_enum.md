# ADS_NAME_TYPE_ENUM enumeration

## Description

The **ADS_NAME_TYPE_ENUM** enumeration specifies the formats used for representing distinguished names. It is used by the [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) interface to convert the format of a distinguished name.

## Constants

### `ADS_NAME_TYPE_1779:1`

Name format as specified in RFC 1779. For example, "CN=Jeff Smith,CN=users,DC=Fabrikam,DC=com".

### `ADS_NAME_TYPE_CANONICAL:2`

Canonical name format. For example, "Fabrikam.com/Users/Jeff Smith".

### `ADS_NAME_TYPE_NT4:3`

Account name format used in Windows. For example, "Fabrikam\JeffSmith".

### `ADS_NAME_TYPE_DISPLAY:4`

Display name format. For example, "Jeff Smith".

### `ADS_NAME_TYPE_DOMAIN_SIMPLE:5`

Simple domain name format. For example, "JeffSmith@Fabrikam.com".

### `ADS_NAME_TYPE_ENTERPRISE_SIMPLE:6`

Simple enterprise name format. For example, "JeffSmith@Fabrikam.com".

### `ADS_NAME_TYPE_GUID:7`

Global Unique Identifier format. For example, "{95ee9fff-3436-11d1-b2b0-d15ae3ac8436}".

### `ADS_NAME_TYPE_UNKNOWN:8`

Unknown name type. The system will estimate the format. This element is a meaningful option only with the [IADsNameTranslate.Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set) or the [IADsNameTranslate.SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex) method, but not with the [IADsNameTranslate.Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-get) or [IADsNameTranslate.GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-getex) method.

### `ADS_NAME_TYPE_USER_PRINCIPAL_NAME:9`

User principal name format. For example, "JeffSmith@Fabrikam.com".

### `ADS_NAME_TYPE_CANONICAL_EX:10`

Extended canonical name format. For example, "Fabrikam.com/Users Jeff Smith".

### `ADS_NAME_TYPE_SERVICE_PRINCIPAL_NAME:11`

Service principal name format. For example, "www/www.fabrikam.com@fabrikam.com".

### `ADS_NAME_TYPE_SID_OR_SID_HISTORY_NAME:12`

A SID string, as defined in the Security Descriptor Definition Language (SDDL), for either the SID of the current object or one from the object SID history. For example, "O:AOG:DAD:(A;;RPWPCCDCLCSWRCWDWOGA;;;S-1-0-0)" For more information, see [Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format).

## Remarks

Code examples written in C++, Visual Basic, and VBS/ASP can be found in the discussions of the [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) interface.

Because VBScript cannot read data from a type library, an application must use the appropriate numeric constants, instead of the symbolic constants, to set the appropriate flags. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here, in VBScript applications.

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)

[IADsNameTranslate.Get](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-get)

[IADsNameTranslate.GetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-getex)

[IADsNameTranslate.Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-set)

[IADsNameTranslate.SetEx](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsnametranslate-setex)

[Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format)