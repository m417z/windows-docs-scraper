# Error_Spec_IPv4 structure

## Description

The
**Error_Spec_IPv4** structure stores error code information for RSVP transmissions.

## Members

### `errs_errnode`

IP address of the node responsible for the error, in the form of an [in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structure.

### `errs_flags`

Error flags. Must be one of the following:

* ERROR_SPECF_InPlace
* ERROR_SPECF_NotGuilty

### `errs_code`

Error code. Must be one of the following:

* ERR_FORWARD_OK
* ERR_Usage_globl
* ERR_Usage_local
* ERR_Usage_serv
* ERR_global_mask

### `errs_value`

Error value.

## See also

[ERROR_SPEC](https://learn.microsoft.com/previous-versions/windows/desktop/api/lpmapi/ns-lpmapi-error_spec)

[in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr)