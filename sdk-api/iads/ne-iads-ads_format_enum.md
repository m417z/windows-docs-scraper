# ADS_FORMAT_ENUM enumeration

## Description

The **ADS_FORMAT_ENUM** enumeration specifies the available path value types used by the [IADsPathname::Retrieve](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-retrieve) method.

## Constants

### `ADS_FORMAT_WINDOWS:1`

Returns the full path in Windows format, for example, "LDAP://servername/o=internet/…/cn=bar".

### `ADS_FORMAT_WINDOWS_NO_SERVER:2`

Returns Windows format without server, for example, "LDAP://o=internet/…/cn=bar".

### `ADS_FORMAT_WINDOWS_DN:3`

Returns Windows format of the distinguished name only, for example, "o=internet/…/cn=bar".

### `ADS_FORMAT_WINDOWS_PARENT:4`

Returns Windows format of Parent only, for example, "o=internet/…".

### `ADS_FORMAT_X500:5`

Returns the full path in X.500 format, for example, "LDAP://servername/cn=bar,…,o=internet".

### `ADS_FORMAT_X500_NO_SERVER:6`

Returns the path without server in X.500 format, for example, "LDAP://cn=bar,…,o=internet".

### `ADS_FORMAT_X500_DN:7`

Returns only the distinguished name in X.500 format. For example, "cn=bar,…,o=internet".

### `ADS_FORMAT_X500_PARENT:8`

Returns only the parent in X.500 format, for example, "…,o=internet".

### `ADS_FORMAT_SERVER:9`

Returns the server name, for example, "servername".

### `ADS_FORMAT_PROVIDER:10`

Returns the name of the provider, for example, "LDAP".

### `ADS_FORMAT_LEAF:11`

Returns the name of the leaf, for example, "cn=bar".

## Remarks

The WinNT provider does not support any of the X.500 format specifiers.

Because Visual Basic Scripting Edition cannot read data from a type library, VBScript applications cannot recognize the symbolic constants as defined above. You should use the numeric constants instead to set the appropriate flags in your VBScript applications. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsPathname::Retrieve](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-retrieve)