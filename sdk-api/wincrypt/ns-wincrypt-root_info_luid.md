# ROOT_INFO_LUID structure

## Description

The **ROOT_INFO_LUID** structure contains a [locally unique identifier](https://learn.microsoft.com/windows/desktop/SecGloss/l-gly) ([LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)) for Cryptographic Smart Card Root Information. The [CRYPT_SMART_CARD_ROOT_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-crypt_smart_card_root_info) structure includes a **ROOT_INFO_LUID** structure.

## Members

### `LowPart`

Low-order bits.

### `HighPart`

High-order bits.

## See also

[LUID](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-luid)