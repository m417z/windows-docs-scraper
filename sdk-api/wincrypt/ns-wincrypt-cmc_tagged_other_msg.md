# CMC_TAGGED_OTHER_MSG structure

## Description

The **CMC_TAGGED_OTHER_MSG** structure is used in the
[CMC_DATA_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_data_info) and
[CMC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_response_info) structures.

## Members

### `dwBodyPartID`

**DWORD** identifying the tagged other message.

### `pszObjId`

Object identifier (OID) of the other message.

### `Value`

A [CRYPT_OBJID_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded other message information.