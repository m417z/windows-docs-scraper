# FWPS_CONNECTION_REDIRECT_STATE_ enumeration

## Description

The FWPS_CONNECTION_REDIRECT_STATE enumeration type specifies the current redirection state of a connection.

## Constants

### `FWPS_CONNECTION_NOT_REDIRECTED`

The connection was not redirected.

### `FWPS_CONNECTION_REDIRECTED_BY_SELF`

The connection was redirected by the calling redirect handle.

### `FWPS_CONNECTION_REDIRECTED_BY_OTHER`

The connection was redirected by a different redirect handle.

### `FWPS_CONNECTION_PREVIOUSLY_REDIRECTED_BY_SELF`

The connection was redirected by the calling redirect handle but later redirected again by a different redirect handle.

### `FWPS_CONNECTION_REDIRECT_STATE_MAX`

The maximum value for this enumeration. This value might change in future versions of the NDIS header files and binaries.

## Remarks

The FWPS_CONNECTION_REDIRECT_STATE enumeration is the return type for a call to the [FwpsQueryConnectionRedirectState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsqueryconnectionredirectstate0) function.

## See also

[FwpsQueryConnectionRedirectState0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsqueryconnectionredirectstate0)