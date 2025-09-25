# IKEEXT_MM_SA_STATE enumeration

## Description

The **IKEEXT_MM_SA_STATE** enumerated type defines the states for the Main Mode (MM) negotiation exchanges that are part of the Authenticated Internet Protocol (AuthIP) and Internet Key Exchange (IKE) protocols.

## Constants

### `IKEEXT_MM_SA_STATE_NONE:0`

Initial state. No packets have been sent to the peer.

### `IKEEXT_MM_SA_STATE_SA_SENT`

First packet has been sent to the peer

### `IKEEXT_MM_SA_STATE_SSPI_SENT`

Second packet has been sent to the peer, for SSPI authentication.

### `IKEEXT_MM_SA_STATE_FINAL`

Third packet has been sent to the peer.

### `IKEEXT_MM_SA_STATE_FINAL_SENT`

Final packet has been sent to the peer.

### `IKEEXT_MM_SA_STATE_COMPLETE`

MM has been completed.

### `IKEEXT_MM_SA_STATE_MAX`

Maximum value for testing purposes.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)