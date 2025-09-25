# CERT_TRUST_LIST_INFO structure

## Description

The **CERT_TRUST_LIST_INFO** structure that indicates valid usage of a CTL.

## Members

### `cbSize`

Size of this structure in bytes.

### `pCtlEntry`

A pointer to a structure that includes a subject identifier, the count of attributes associated with a CTL, and an array of those attributes.

### `pCtlContext`

A pointer to a CTL context.

## See also

[CERT_CHAIN_ELEMENT](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_chain_element)

[CTL_ENTRY](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-ctl_entry)