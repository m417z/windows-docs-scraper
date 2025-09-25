# CryptCATPutAttrInfo function

## Description

[The **CryptCATPutAttrInfo** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATPutAttrInfo** function allocates memory for an attribute and adds it to a catalog member.

## Parameters

### `hCatalog` [in]

A handle to the catalog obtained from the [CryptCATOpen](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcatopen) or [CryptCATHandleFromStore](https://learn.microsoft.com/windows/desktop/api/mscat/nf-mscat-cryptcathandlefromstore) function.

### `pCatMember` [in]

A pointer to a [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that contains the catalog member.

### `pwszReferenceTag` [in]

A pointer to a null-terminated string that contains the name of the attribute.

### `dwAttrTypeAndAction` [in]

A value that represents a bitwise combination of the following flags. The caller must at least specify **CRYPTCAT_ATTR_DATABASE64** or **CRYPTCAT_ATTR_DATAASCII**.

| Value | Meaning |
| --- | --- |
| **CRYPTCAT_ATTR_AUTHENTICATED**<br><br>0x10000000 | The attribute is authenticated. |
| **CRYPTCAT_ATTR_UNAUTHENTICATED**<br><br>0x20000000 | The attribute is unauthenticated. |
| **CRYPTCAT_ATTR_NAMEASCII**<br><br>0x00000001 | The attribute is an ASCII string. |
| **CRYPTCAT_ATTR_NAMEOBJID**<br><br>0x00000002 | The attribute is a cryptographic [object identifier](https://learn.microsoft.com/windows/desktop/SecGloss/o-gly) (OID). |
| **CRYPTCAT_ATTR_DATAASCII**<br><br>0x00010000 | The attribute contains simple ASCII characters that should not be decoded. |
| **CRYPTCAT_ATTR_DATABASE64**<br><br>0x00020000 | The attribute is in base 64 format. |
| **CRYPTCAT_ATTR_DATAREPLACE**<br><br>0x00040000 | The attribute replaces the value for an existing attribute. |

### `cbData` [in]

A value that specifies the number of bytes in the *pbData* buffer.

### `pbData` [in]

A pointer to a memory buffer that contains the attribute value.

## Return value

Upon success, this function returns a pointer to a [CRYPTCATATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatattribute) structure that contains the assigned attribute. The caller must not free this pointer or any of its members.

If this function returns **NULL**, additional error information can be obtained by calling the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. **GetLastError** will return one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters are not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The operating system ran out of memory during the operation. |