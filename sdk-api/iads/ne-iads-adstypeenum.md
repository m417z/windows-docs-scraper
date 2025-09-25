# ADSTYPEENUM enumeration

## Description

The **ADSTYPEENUM** enumeration is used to identify the data type of an ADSI property value.

## Constants

### `ADSTYPE_INVALID:0`

The data type is not valid

### `ADSTYPE_DN_STRING`

The string is of Distinguished Name (path) of a directory service object.

### `ADSTYPE_CASE_EXACT_STRING`

The string is of the case-sensitive type.

### `ADSTYPE_CASE_IGNORE_STRING`

The string is of the case-insensitive type.

### `ADSTYPE_PRINTABLE_STRING`

The string is displayable on screen or in print.

### `ADSTYPE_NUMERIC_STRING`

The string is of a numeral to be interpreted as text.

### `ADSTYPE_BOOLEAN`

The data is of a Boolean value.

### `ADSTYPE_INTEGER`

The data is of an integer value.

### `ADSTYPE_OCTET_STRING`

The string is of a byte array.

### `ADSTYPE_UTC_TIME`

The data is of the universal time as expressed in Universal Time Coordinate (UTC).

### `ADSTYPE_LARGE_INTEGER`

The data is of a long integer value.

### `ADSTYPE_PROV_SPECIFIC`

The string is of a provider-specific string.

### `ADSTYPE_OBJECT_CLASS`

Not used.

### `ADSTYPE_CASEIGNORE_LIST`

The data is of a list of case insensitive strings.

### `ADSTYPE_OCTET_LIST`

The data is of a list of octet strings.

### `ADSTYPE_PATH`

The string is of a directory path.

### `ADSTYPE_POSTALADDRESS`

The string is of the postal address type.

### `ADSTYPE_TIMESTAMP`

The data is of a time stamp in seconds.

### `ADSTYPE_BACKLINK`

The string is of a back link.

### `ADSTYPE_TYPEDNAME`

The string is of a typed name.

### `ADSTYPE_HOLD`

The data is of the Hold data structure.

### `ADSTYPE_NETADDRESS`

The string is of a net address.

### `ADSTYPE_REPLICAPOINTER`

The data is of a replica pointer.

### `ADSTYPE_FAXNUMBER`

The string is of a fax number.

### `ADSTYPE_EMAIL`

The data is of an email message.

### `ADSTYPE_NT_SECURITY_DESCRIPTOR`

The data is a Windows security descriptor as represented by a byte array.

### `ADSTYPE_UNKNOWN`

The data is of an undefined type.

### `ADSTYPE_DN_WITH_BINARY`

The data is of [ADS_DN_WITH_BINARY](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_binary) used for mapping a distinguished name to a nonvarying GUID. For more information, see Remarks.

### `ADSTYPE_DN_WITH_STRING`

The data is of [ADS_DN_WITH_STRING](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_string) used for mapping a distinguished name to a nonvarying string value. For more information, see Remarks.

## Remarks

When extending the active directory schema to add [ADS_DN_WITH_BINARY](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_binary), you must also specify the "otherWellKnownGuid" attribute definition. Add the following to the ldf file attribute definition: "omObjectClass:: KoZIhvcUAQEBCw=="

When extending the active directory schema to add [ADS_DN_WITH_STRING](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_string), you must also specify the "otherWellKnownGuid" attribute definition. Add the following to the ldf file attribute definition: "omObjectClass:: KoZIhvcUAQEBDA=="

Because VBScript cannot read data from a type library, VBScript applications do not recognize symbolic constants, as defined above. Use the numerical constants instead to set the appropriate flags in your VBScript application. To use the symbolic constants as a good programming practice, write explicit declarations of such constants, as done here, in your VBScript application.

## See also

[ADSI Enumerations](https://learn.microsoft.com/windows/desktop/ADSI/adsi-enumerations)