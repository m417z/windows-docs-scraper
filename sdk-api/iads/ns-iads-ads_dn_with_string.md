# ADS_DN_WITH_STRING structure

## Description

The **ADS_DN_WITH_STRING** structure is used with the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure to contain a distinguished name attribute value that also contains string data.

## Members

### `pszStringValue`

Pointer to a null-terminated Unicode string that contains the string value of the attribute.

### `pszDNString`

Pointer to a null-terminated Unicode string that contains the distinguished name.

## Remarks

When extending the active directory schema to add **ADS_DN_WITH_STRING**, you must also specify the otherWellKnownGuid attribute definition. Add the following to the ldf file attribute definition: omObjectClass:: KoZIhvcUAQEBDA==

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue)

[Object(DN-String)](https://learn.microsoft.com/windows/desktop/ADSchema/s-object-dn-string)