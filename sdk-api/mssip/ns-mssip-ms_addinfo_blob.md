# MS_ADDINFO_BLOB structure

## Description

The **MS_ADDINFO_BLOB** structure provides additional information for in-memory [BLOB](https://learn.microsoft.com/windows/desktop/SecGloss/b-gly) subject types.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `cbMemObject`

The size, in bytes, of the data in the *pbMemObject* member.

### `pbMemObject`

A pointer to the in-memory BLOB subject.

### `cbMemSignedMsg`

The size, in bytes, of the data in the *pbMemSignedMsg* member.

### `pbMemSignedMsg`

A pointer to the signed message.