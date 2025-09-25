# ADSVALUE structure

## Description

The **ADSVALUE** structure contains a value specified as an ADSI data type. These data types can be [ADSI Simple Data Types](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types) or ADSI-defined custom data types that include C-style structures.

The [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info) structure contains an array of **ADSVALUE** structures. Each **ADSVALUE** structure contains a single attribute value.

## Members

### `dwType`

Data type used to interpret the union member of the structure. Values of this member are taken from the [ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum) enumeration.

### `DNString`

The null-terminated Unicode string that identifies the distinguished name (path) of a directory service object, as defined by **ADS_DN_STRING**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `CaseExactString`

The null-terminated Unicode string to be interpreted case-sensitively, as defined by **ADS_CASE_EXACT_STRING**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `CaseIgnoreString`

The null-terminated Unicode string to be interpreted without regard to case, as defined by **ADS_CASE_IGNORE_STRING**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `PrintableString`

The null-terminated Unicode string that can be displayed or printed, as defined by **ADS_PRINTABLE_STRING**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `NumericString`

The null-terminated Unicode string that contains numerals to be interpreted as text, as defined by **ADS_NUMERIC_STRING**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `Boolean`

Boolean value, as defined by **ADS_BOOLEAN**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `Integer`

Integer value, as defined by **ADS_INTEGER**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `OctetString`

An octet string, as defined by [ADS_OCTET_STRING](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_octet_string), an ADSI-defined data type.

### `UTCTime`

Time specified as Coordinated Universal Time (UTC), as defined by **ADS_UTC_TIME**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `LargeInteger`

Long integer value, as defined by **ADS_LARGE_INTEGER**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `ClassName`

Class name string, as defined by **ADS_OBJECT_CLASS**, an [ADSI simple data type](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types).

### `ProviderSpecific`

Provider-specific structure, as defined by [ADS_PROV_SPECIFIC](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_prov_specific), an ADSI-defined data type.

### `pCaseIgnoreList`

Pointer to a [ADS_CASEIGNORE_LIST](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_caseignore_list), an ADSI-defined data type.

### `pOctetList`

Pointer to a list of [ADS_OCTET_LIST](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_octet_list), an ADSI-defined data type.

### `pPath`

Pointer to the [ADS_PATH](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_path) name, an ADSI-defined data type.

### `pPostalAddress`

Pointer to the [ADS_POSTALADDRESS](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_postaladdress) data, an ADSI-defined data type.

### `Timestamp`

Time stamp of the [ADS_TIMESTAMP](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_timestamp) type, an ADSI-defined data type.

### `BackLink`

A link of the [ADS_BACKLINK](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_backlink) type, an ADSI-defined data type.

### `pTypedName`

Pointer to the [ADS_TYPEDNAME](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_typedname) name, an ADSI-defined data type.

### `Hold`

A data structure of the [ADS_HOLD](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_hold) type, an ADSI-defined data type.

### `pNetAddress`

Pointer to the [ADS_NETADDRESS](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_netaddress) data, an ADSI-defined data type.

### `pReplicaPointer`

Pointer to a replica pointer of [ADS_REPLICAPOINTER](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_replicapointer), an ADSI-defined data type.

### `pFaxNumber`

Pointer to a facsimile number of [ADS_FAXNUMBER](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_faxnumber), an ADSI-defined data type.

### `Email`

Email address of a user of [ADS_EMAIL](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_email), an ADSI-defined data type.

### `SecurityDescriptor`

Windows security descriptor, as defined by [ADS_NT_SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_nt_security_descriptor), an ADSI-defined data type.

### `pDNWithBinary`

Pointer to an [ADS_DN_WITH_BINARY](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_binary) structure that maps a distinguished name of an object to its GUID value.

### `pDNWithString`

Pointer to an [ADS_DN_WITH_STRING](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_string) structure that maps a distinguished name of an object to a nonvarying string value.

## Remarks

Members of the **ADSVALUE** structure specify the data type of attributes. For more information and a code example, see [ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info).

## See also

[ADSI Simple Data
Types](https://learn.microsoft.com/windows/desktop/ADSI/adsi-simple-data-types)

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSTYPEENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-adstypeenum)

[ADS_ATTR_INFO](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_attr_info)

[ADS_BACKLINK](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_backlink)

[ADS_CASEIGNORE_LIST](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_caseignore_list)

[ADS_DN_WITH_BINARY](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_binary)

[ADS_DN_WITH_STRING](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_dn_with_string)

[ADS_EMAIL](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_email)

[ADS_FAXNUMBER](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_faxnumber)

[ADS_HOLD](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_hold)

[ADS_NETADDRESS](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_netaddress)

[ADS_NT_SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_nt_security_descriptor)

[ADS_OCTET_LIST](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-ads_octet_list)

[ADS_OCTET_STRING](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_octet_string)

[ADS_PATH](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_path)

[ADS_POSTALADDRESS](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_postaladdress)

[ADS_PROV_SPECIFIC](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_prov_specific)

[ADS_REPLICAPOINTER](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_replicapointer)

[ADS_TIMESTAMP](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_timestamp)

[ADS_TYPEDNAME](https://learn.microsoft.com/windows/win32/api/iads/ns-iads-ads_typedname)

[IDirectoryObject::CreateDSObject](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-createdsobject)

[IDirectoryObject::GetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-getobjectattributes)

[IDirectoryObject::SetObjectAttributes](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectoryobject-setobjectattributes)

[IDirectorySearch::SetSearchPreference](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-idirectorysearch-setsearchpreference)