# CMC_TAGGED_CONTENT_INFO structure

## Description

The **CMC_TAGGED_CONTENT_INFO** structure is used in the
[CMC_DATA_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_data_info) and
[CMC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_response_info) structures.

## Members

### `dwBodyPartID`

**DWORD** identifying the tagged other message.

### `EncodedContentInfo`

A [CRYPT_DER_BLOB](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa381414(v=vs.85)) structure that contains the encoded content information.