# CMC_RESPONSE_INFO structure

## Description

The **CMC_RESPONSE_INFO** structure provides a means of communicating different pieces of tagged information.

## Members

### `cTaggedAttribute`

Count of the number of elements in the **rgTaggedAttribute** member array.

### `rgTaggedAttribute`

Array of
[CMC_TAGGED_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_tagged_attribute) structures.

### `cTaggedContentInfo`

Count of the number of elements in the **rgTaggedContentInfo** member array.

### `rgTaggedContentInfo`

Array of
[CMC_TAGGED_CONTENT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_tagged_content_info) structures.

### `cTaggedOtherMsg`

Count of the number of elements in the **rgTaggedOtherMsg** member array.

### `rgTaggedOtherMsg`

Array of
[CMC_TAGGED_OTHER_MSG](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cmc_tagged_other_msg) structures.

## Remarks

All tagged arrays are optional.