# CROSS_CERT_DIST_POINTS_INFO structure

## Description

The **CROSS_CERT_DIST_POINTS_INFO** structure provides information used to update dynamic cross certificates.

## Members

### `dwSyncDeltaTime`

**DWORD** indicating seconds between synchronization. If this member is zero, the client default synchronization time is used.

### `cDistPoint`

Count of the number of elements in the **rgDistPoint** member array.

### `rgDistPoint`

Array of
[CERT_ALT_NAME_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_alt_name_info) structures for distribution points for updating cross certificates.