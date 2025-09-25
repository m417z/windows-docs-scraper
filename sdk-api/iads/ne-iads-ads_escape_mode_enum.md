# ADS_ESCAPE_MODE_ENUM enumeration

## Description

The **ADS_ESCAPE_MODE_ENUM** enumeration specifies how escape characters are displayed in a directory path.

## Constants

### `ADS_ESCAPEDMODE_DEFAULT:1`

The default escape mode provides a convenient option to specify the escape mode. It has the effect of minimal escape operation appropriate for a chosen format. Thus, the default behavior depends on the value that [ADS_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_format_enum) uses to retrieve the directory paths.

| Retrieved path format | Default escaped mode |
| --- | --- |
| **ADS_FORMAT_X500** | **ADS_ESCAPEDMODE_ON** |
| **ADS_FORMAT_X500_NO_SERVER** | **ADS_ESCAPEDMODE_ON** |
| **ADS_FORMAT_WINDOWS** | **ADS_ESCAPEDMODE_ON** |
| **ADS_FORMAT_WINDOWS_NO_SERVER** | **ADS_ESCAPEDMODE_ON** |
| **ADS_FORMAT_X500_DN** | **ADS_ESCAPEDMODE_OFF** |
| **ADS_FORMAT_X500_PARENT** | **ADS_ESCAPEDMODE_OFF** |
| **ADS_FORMAT_WINDOWS_DN** | **ADS_ESCAPEDMODE_OFF** |
| **ADS_FORMAT_WINDOWS_PARENT** | **ADS_ESCAPEDMODE_OFF** |
| **ADS_FORMAT_LEAF** | **ADS_ESCAPEDMODE_ON** |

### `ADS_ESCAPEDMODE_ON:2`

All special characters are displayed in the escape format; for example, "CN=date\=yy\/mm\/dd\,weekday" appears as is.

### `ADS_ESCAPEDMODE_OFF:3`

ADSI special characters are displayed in the unescaped format; for example, "CN=date\=yy\/mm\/dd\,weekday" appears as "CN=date\=yy/mm/dd\,weekday".

### `ADS_ESCAPEDMODE_OFF_EX:4`

ADSI and LDAP special characters are displayed in the unescaped format; for example, "CN=date\=yy\/mm\/dd\,weekday" appears as "CN=date=yy/mm/dd,weekday".

## Remarks

Special characters must be escaped when used for any unintended purposes. For example, LDAP special characters, the comma (,) and the equal sign (=), are intended as field separators in a distinguished name, "CN=user,CN=users,DC=Fabrikam,DC=com". When an attribute value uses such special characters, for example, "CN=users\,last name\=Smith", these special characters must be escaped as shown. This ensures that an LDAP-compliant directory, such as Active Directory, will parse the path properly. However, an escaped path string may not appear to be user-friendly on a display. In this case, you can set the **ADS_ESCAPE_MODE_ENUM** in such way that shows the path as an unescaped string, "CN=users,last name=Smith".

Similarly, the ADSI special character, slash mark (/), separates ADSI-specific elements, "LDAP://server/CN=Jeff Smith,CN=Users,DC=Fabrikam,DC=com". Although it must be escaped when used for any other purposes, for example, "LDAP://server/CN=Jeff Smith\/California,CN=Users,DC=Fabrikam,DC=com". You can choose an **ADS_ESCAPE_MODE_ENUM** option to display this escaped string in a human-readable form: "LDAP://server/CN=Jeff Smith/California,CN=Users,DC=Fabrikam,DC=com".

Presently, the slash mark (/) is the only ADSI special character. ADSI escaping and unescaping applies to ADSI special characters only. The operation will not affect any LDAP special characters, that is, they are neither escaped nor unescaped. For more information and a list of special characters defined by LDAP, see [LDAP Special Characters](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath).

To show unescaped path string, use
the [IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname) interface and its methods. All other ADSI APIs return the escaped path string.

To obtain correct behavior, the LDAP special characters must be escaped before the ADSI special characters are escaped. The [IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname) interface will escape the characters in the correct sequence.

**Note** Because VBScript cannot read data from a type library, Visual Basic Scripting Edition (VBScript) applications do not recognize symbolic, as constants defined above. Instead, use the numerical constants instead to set the appropriate flags in your VBScript applications. To use the symbolic constants, write explicit declarations of such constants, as done here.

## See also

[ADSI
Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[ADS_FORMAT_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_format_enum)

[IADsPathname](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadspathname)

[LDAP ADsPath](https://learn.microsoft.com/windows/desktop/ADSI/ldap-adspath)