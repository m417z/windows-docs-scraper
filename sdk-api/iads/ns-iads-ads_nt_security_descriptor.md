# ADS_NT_SECURITY_DESCRIPTOR structure

## Description

The **ADS_NT_SECURITY_DESCRIPTOR** structure defines the data type of the security descriptor for Windows.

## Members

### `dwLength`

The length data, in bytes.

### `lpValue`

Pointer to the security descriptor, represented as a byte array.

## Remarks

The **ADS_NT_SECURITY_DESCRIPTOR** structure is normally used as a member of the [ADSVALUE](https://learn.microsoft.com/windows/desktop/api/iads/ns-iads-adsvalue) structure definition.

## See also

[ADSI Structures](https://learn.microsoft.com/windows/desktop/ADSI/adsi-structures)