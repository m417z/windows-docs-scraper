# CMC_TAGGED_ATTRIBUTE structure

## Description

The **CMC_TAGGED_ATTRIBUTE** structure is used in the
[CMC_DATA_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_data_info) and
[CMC_RESPONSE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_response_info) structures.

## Members

### `dwBodyPartID`

A **DWORD** value that identifies the tagged attribute.

### `Attribute`

A [CRYPT_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_attribute) structure that contains the attribute.