# CRYPTCATMEMBER structure

## Description

[The **CRYPTCATMEMBER** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CRYPTCATMEMBER** structure provides information about a catalog member. This structure is used by the [CryptCATGetMemberInfo](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatgetmemberinfo) and [CryptCATEnumerateAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumerateattr) functions.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pwszReferenceTag`

A pointer to a null-terminated string that contains the reference tag value.

### `pwszFileName`

A pointer to a null-terminated string that contains the file name.

### `gSubjectType`

**GUID** that identifies the subject type.

### `fdwMemberFlags`

Value that specifies the member flags.

### `pIndirectData`

A pointer to a **SIP_INDIRECT_DATA** structure.

### `dwCertVersion`

Value that specifies the certificate version.

### `dwReserved`

Reserved; do not use.

### `hReserved`

Reserved; do not use.

### `sEncodedIndirectData`

A [CRYPT_ATTR_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains encoded indirect data.

### `sEncodedMemberInfo`

A [CRYPT_ATTR_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains encoded member information.

## See also

[CryptCATEnumerateAttr](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatenumerateattr)

[CryptCATGetMemberInfo](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatgetmemberinfo)