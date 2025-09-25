## Description

Defines a callback function that WDS can call for progress notification and error messages during a file or image transfer.

## Parameters

### `dwMessageId` [in]

The type of message and the meaning of the *lParam* parameter.

This parameter can have only one of the following values.

| Value | Meaning |
| --- | --- |
| **WDS_CLI_MSG_START**<br><br>0 | The transfer start message. The *lParam* parameter is a pointer to a **LARGE_INTEGER** value containing the file size of the transfer. |
| **WDS_CLI_MSG_COMPLETE**<br><br>1 | The transfer complete message. The *lParam* parameter is an **HRESULT** value. |
| **WDS_CLI_MSG_PROGRESS**<br><br>2 | The transfer progress message. The *lParam* parameter is a **ULONG** value that is the percentage of transfer completed. |
| **WDS_CLI_MSG_TEXT**<br><br>3 | The informational message. The *lParam* parameter is pointer to a debugging string that can be used for diagnostic purposes. |

### `wParam` [in, optional]

This message parameter should always be set to the value of the transfer handle returned by the
[WdsCliTransferImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferimage) or
[WdsCliTransferFile](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferfile) function.

### `lParam` [in, optional]

The meaning of the value contained by this parameter depends upon the
*dwMessageId* parameter.

### `pvUserData` [in, optional]

A pointer to optional user information attached to this session by the
[WdsCliTransferImage](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferimage) or
[WdsCliTransferFile](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclitransferfile) function.

## Remarks

A callback function can call the
[WdsCliCancelTransfer](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdsclicanceltransfer) function to cancel a
transfer. Although a callback function can also call the
[WdsCliWaitForTransfer](https://learn.microsoft.com/windows/desktop/api/wdsclientapi/nf-wdsclientapi-wdscliwaitfortransfer) function, this is not
recommended because no additional callbacks will be received until the current callback is unblocked.