# PEER_GROUP_ISSUE_CREDENTIAL_FLAGS enumeration

## Description

The **PEER_GROUP_ISSUE_CREDENTIAL_FLAGS** are used to specify if user credentials are stored within a group.

## Constants

### `PEER_GROUP_STORE_CREDENTIALS:0x0001`

When the **PEER_GROUP_STORE_CREDENTIALS** flag is set, the user credentials are stored within a group database to be retrieved when the user connects. If the flag is not set, any new credentials are returned in string form and must be passed to the user out-of-band.