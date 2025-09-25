# PFN_CDF_PARSE_ERROR_CALLBACK callback function

## Description

The **PFN_CDF_PARSE_ERROR_CALLBACK** function is called for [Catalog Definition Function](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions) errors while parsing a catalog definition file (CDF).

## Parameters

### `dwErrorArea` [in]

A value that indicates in which area of the CDF the error occurred.

### `dwLocalError` [in]

A value that indicates the type of error.

### `pwszLine` [in]

A pointer to a null-terminated string that contains the CDF line in which the error occurred.

## Remarks

The *dwErrorArea* parameter can have the following possible values.

| Value | Description |
| --- | --- |
| CRYPTCAT_E_AREA_HEADER | The header section of the CDF |
| CRYPTCAT_E_AREA_MEMBER | A member file entry in the CatalogFiles section of the CDF |
| CRYPTCAT_E_AREA_ATTRIBUTE | An attribute entry in the CDF |

The *dwLocalError* parameter can have the following possible values.

| Value | Description |
| --- | --- |
| CRYPTCAT_E_CDF_UNSUPPORTED | The function does not support the attribute. |
| CRYPTCAT_E_CDF_DUPLICATE | The file member already exists. |
| CRYPTCAT_E_CDF_TAGNOTFOUND | The CatalogHeader or Name tag is missing. |
| CRYPTCAT_E_CDF_MEMBER_FILE_PATH | The member file name or path is missing. |
| CRYPTCAT_E_CDF_MEMBER_INDIRECTDATA | The function failed to create a hash of the member subject. |
| CRYPTCAT_E_CDF_MEMBER_FILENOTFOUND | The function failed to find the member file. |
| CRYPTCAT_E_CDF_BAD_GUID_CONV | The function failed to convert the subject string to a GUID. |
| CRYPTCAT_E_CDF_ATTR_TOOFEWVALUES | The attribute line is missing one or more elements of its composition including type, [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID) or name, or value. |
| CRYPTCAT_E_CDF_ATTR_TYPECOMBO | The attribute contains an invalid OID, or the combination of type, name or OID, and value is not valid. |

## See also

[Catalog Definition Function](https://learn.microsoft.com/windows/desktop/SecCrypto/cryptography-functions)