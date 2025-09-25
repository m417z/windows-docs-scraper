# IKEEXT_EM_SA_STATE enumeration

## Description

The **IKEEXT_EM_SA_STATE** enumerated type defines the states for the Extended Mode (EM) negotiation exchanges that are part of the Authenticated Internet Protocol (AuthIP) protocol.

## Constants

### `IKEEXT_EM_SA_STATE_NONE:0`

Initial state. No Extended Mode packets have been sent to the peer.

### `IKEEXT_EM_SA_STATE_SENT_ATTS`

First packet has been sent to the peer.

### `IKEEXT_EM_SA_STATE_SSPI_SENT`

Second packet has been sent to the peer.

### `IKEEXT_EM_SA_STATE_AUTH_COMPLETE`

Third packet has been sent to the peer.

### `IKEEXT_EM_SA_STATE_FINAL`

Final packet has been sent to the peer.

### `IKEEXT_EM_SA_STATE_COMPLETE`

Extended mode has been completed.

### `IKEEXT_EM_SA_STATE_MAX`

Maximum value for testing purposes.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)