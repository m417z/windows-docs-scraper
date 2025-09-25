# CRYPTCATATTRIBUTE structure

## Description

[The **CRYPTCATATTRIBUTE** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTCATATTRIBUTE** structure defines a catalog attribute. This structure is used by the [CryptCATEnumerateAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumerateattr) and [CryptCATEnumerateCatAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumeratecatattr) functions.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pwszReferenceTag`

A pointer to a null-terminated string that contains the reference tag value.

### `dwAttrTypeAndAction`

Bitwise combination of the following flags.

| Value | Meaning |
| --- | --- |
| **CRYPTCAT_ATTR_AUTHENTICATED**<br><br>0x10000000 | The attribute is authenticated. |
| **CRYPTCAT_ATTR_UNAUTHENTICATED**<br><br>0x20000000 | The attribute is unauthenticated. |
| **CRYPTCAT_ATTR_NAMEASCII**<br><br>0x00000001 | The attribute is an ASCII string. |
| **CRYPTCAT_ATTR_NAMEOBJID**<br><br>0x00000002 | The attribute is a cryptographic object identifier (OID). |
| **CRYPTCAT_ATTR_DATAASCII**<br><br>0x00010000 | The attribute contains simple ASCII characters that should not be decoded. |
| **CRYPTCAT_ATTR_DATABASE64**<br><br>0x00020000 | The attribute is in base 64 format. |
| **CRYPTCAT_ATTR_DATAREPLACE**<br><br>0x00040000 | The attribute replaces the value for an existing attribute. |

### `cbValue`

Number of bytes used by **pbValue**.

### `pbValue`

A pointer to the encoded bytes.

### `dwReserved`

Reserved; do not use.

## See also

[CryptCATEnumerateAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumerateattr)

[CryptCATEnumerateCatAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumeratecatattr)