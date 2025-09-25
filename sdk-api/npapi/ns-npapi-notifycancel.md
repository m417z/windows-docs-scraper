# NOTIFYCANCEL structure

## Description

The **NOTIFYCANCEL** structure contains the details of a network disconnect operation. It is used by the
[CancelConnectNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-cancelconnectnotify) function.

## Members

### `lpName`

Pointer to the name of the local device or network resource whose connection is being canceled.

### `lpProvider`

For advance notification, this field is not defined. The MPR will try all valid providers to cancel the connection.

For after-the-fact notification, if the cancel operation was successful, this field specifies the name of the network provider that canceled the connection.

### `dwFlags`

Currently, the only flag supported is CONNECT_UPDATE_PROFILE, which indicates whether the disconnection should remain persistent. If this flag is set, Windows no longer restores this connection when the user logs on.

### `fForce`

Indicates whether the disconnect should continue even if there are open files or jobs on the connection. If this field is **TRUE**, the connection is canceled regardless of open files or jobs. If this field is **FALSE**, the connection will not be canceled if there are open files or jobs.