# WdsCliTransferFile function

## Description

Transfers a file from a WDS server to the WDS client using a multicast transfer protocol.

## Parameters

### `pwszServer` [in]

A pointer to a null-terminated string value that contains the WDS server name.

### `pwszNamespace` [in]

A pointer to a null-terminated string value that contains the multicast namespace name for the image.

### `pwszRemoteFilePath` [in]

A pointer to a null-terminated string value that contains the full path for the remote location from which to copy the file being transferred.

### `pwszLocalFilePath` [in]

A pointer to a null-terminated string value that contains the full path to the local location to store the file being transferred.

### `dwFlags` [in]

Options associated with the file transfer.

| Value | Meaning |
| --- | --- |
| **WDS_CLI_TRANSFER_ASYNCHRONOUS** | This flag specifies an asynchronous transfer. |

### `dwReserved` [in]

This parameter is reserved.

### `pfnWdsCliCallback` [in, optional]

A pointer to an optional callback function for this transfer.

### `pvUserData` [in, optional]

A pointer to optional user information that can be passed to the callback function.

### `phTransfer` [out]

A pointer to a transfer handle that can be used with the [WdsCliWaitForTransfer](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliwaitfortransfer) or [WdsCliCancelTransfer](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicanceltransfer) functions to wait for the transfer to complete or to cancel the transfer.

## Return value

If the function succeeds, the return is **S_OK**.

## Remarks

Call the [WdsCliClose](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliclose) function to close the handle returned by this function.