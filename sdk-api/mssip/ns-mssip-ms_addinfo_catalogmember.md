# MS_ADDINFO_CATALOGMEMBER structure

## Description

The **MS_ADDINFO_CATALOGMEMBER** structure provides additional information for catalog member subject types.

## Members

### `cbStruct`

The size, in bytes, of this structure.

### `pStore`

A [CRYPTCATSTORE](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatstore) structure that contains a catalog file store.

### `pMember`

A [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that contains a catalog member.