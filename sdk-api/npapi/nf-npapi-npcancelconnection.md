# NPCancelConnection function

## Description

The **NPCancelConnection** function disconnects a network connection. The changes you make to the connection are remembered if the connection is to a device. If, however, the connection is to a remote network resource, changes are not remembered.

## Parameters

### `lpName` [in]

Pointer to the name of either the redirected local device or the remote network resource to disconnect from.

### `fForce` [in]

Indicates whether the disconnect should continue in the event of open files or jobs on the connection. If **FALSE** is specified, the call will fail if there are open files or jobs.

## Return value

If the function succeeds, it will return WN_SUCCESS. Otherwise, it will return an error. This can be one of the following.

| Return code | Description |
| --- | --- |
| **WN_NOT_CONNECTED** | *lpName* is not a redirected device or is not currently connected to *lpName*. |
| **WN_OPEN_FILES** | There are open files, and *fForce* was set to **FALSE**. |