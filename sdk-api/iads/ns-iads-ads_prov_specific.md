# ADS_PROV_SPECIFIC structure

## Description

The **ADS_PROV_SPECIFIC** structure contains provider-specific data represented as a binary large object (BLOB).

## Members

### `dwLength`

The size of the character array.

### `lpValue`

A pointer to an array of bytes.

## Remarks

The **ADS_PROV_SPECIFIC** structure is one of the data types used as a member of the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure definition. The data is represented as a BLOB here, although the actual data can be packed in any format, such as a C structure. The provider writer must publish the specific data format under the BLOB.

ADSI may also return attributes as **ADS_PROV_SPECIFIC** if unable to determine the correct attribute syntax type as would occur if, for example, the schema was unavailable.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)

[ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue)