# CERT_NAME_CONSTRAINTS_INFO structure

## Description

The **CERT_NAME_CONSTRAINTS_INFO** structure contains information about certificates that are specifically permitted or excluded from trust.

## Members

### `cPermittedSubtree`

**DWORD** indicating the number of subtrees in the **rgPermittedSubtree** array.

### `rgPermittedSubtree`

Array of
[CERT_GENERAL_SUBTREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_general_subtree) structures, each identifying a permitted certificate name.

### `cExcludedSubtree`

**DWORD** indicating the number of subtrees in the **rgExcludedSubtree** array.

### `rgExcludedSubtree`

Array of [CERT_GENERAL_SUBTREE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_general_subtree) structures, each identifying an excluded certificate name.