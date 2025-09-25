# ADS_OCTET_STRING structure

## Description

The **ADS_OCTET_STRING** structure is an ADSI representation of the **Octet String** attribute syntax used in Active Directory.

## Members

### `dwLength`

The size, in bytes, of the character array.

### `lpValue`

Pointer to an array of single byte characters
not interpreted by the underlying directory.

## Remarks

Memory for the byte array must be allocated separately.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)