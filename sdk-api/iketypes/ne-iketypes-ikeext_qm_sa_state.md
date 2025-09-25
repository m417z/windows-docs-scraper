# IKEEXT_QM_SA_STATE enumeration

## Description

The **IKEEXT_QM_SA_STATE** enumerated type defines the states for the Quick Mode (QM) negotiation exchanges that are part of the Authenticated Internet Protocol (AuthIP) and Internet Key Exchange (IKE) protocols.

## Constants

### `IKEEXT_QM_SA_STATE_NONE:0`

Initial state. No QM packets have been sent to the peer.

### `IKEEXT_QM_SA_STATE_INITIAL`

First packet has been sent to the peer.

### `IKEEXT_QM_SA_STATE_FINAL`

Final packet has been sent to the peer.

### `IKEEXT_QM_SA_STATE_COMPLETE`

QM has been completed.

### `IKEEXT_QM_SA_STATE_MAX`

Maximum value for testing purposes.

## See also

[Windows Filtering Platform API Enumerated Types](https://learn.microsoft.com/windows/desktop/FWP/fwp-enums)