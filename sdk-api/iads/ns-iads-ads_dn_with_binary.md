# ADS_DN_WITH_BINARY structure

## Description

The **ADS_DN_WITH_BINARY** structure is used with the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure to contain a distinguished name attribute value that also contains binary data.

## Members

### `dwLength`

Contains the length, in bytes, of the binary data in **lpBinaryValue**.

### `lpBinaryValue`

Pointer to an array of bytes that contains the binary data for the attribute. The **dwLength** member contains the number of bytes in this array.

### `pszDNString`

Pointer to a null-terminated Unicode string that contains the distinguished name.

## Remarks

When extending the active directory schema to add **ADS_DN_WITH_BINARY**, you must also specify the otherWellKnownGuid attribute definition. Add the following to the ldf file attribute definition: omObjectClass:: KoZIhvcUAQEBCw==

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue)

[Object(DN-Binary)](https://learn.microsoft.com/windows/desktop/ADSchema/s-object-dn-binary)