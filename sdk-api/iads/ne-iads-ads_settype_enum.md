# ADS_SETTYPE_ENUM enumeration

## Description

The **ADS_SETTYPE_ENUM** enumeration specifies the available pathname format used by the [IADsPathname::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-set) method.

## Constants

### `ADS_SETTYPE_FULL:1`

Sets the full path, for example, "LDAP://servername/o=internet/…/cn=bar".

### `ADS_SETTYPE_PROVIDER:2`

Updates the provider only, for example, "LDAP".

### `ADS_SETTYPE_SERVER:3`

Updates the server name only, for example, "servername".

### `ADS_SETTYPE_DN:4`

Updates the distinguished name only, for example, "o=internet/…/cn=bar".

## Remarks

Since VBScript cannot read information from a type library, VBScript applications do not understand the symbolic constants as defined above. You should use the numerical constants instead to set the appropriate flags in your VBScript applications. If you want to use the symbolic constants as a good programming practice, you should make explicit declarations of such constants, as done here, in your VBScript applications.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)

[IADsPathname::Set](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadspathname-set)