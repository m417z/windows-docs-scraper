# ITransferAdviseSink::ConfirmEncryptionLoss

## Description

Displays a message to the user confirming that loss of encryption is acceptable for this operation.

## Parameters

### `psiSource`

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) of the file in which encryption information will be lost.

## Return value

Type: **HRESULT**

Returns one of the following specific Shell codes, or a system error code.

| Return code | Description |
| --- | --- |
| **COPYENGINE_S_YES** | User responded "Yes" to the dialog. Copy continues without encryption. |
| **COPYENGINE_S_USER_IGNORED** | User responded "No" to the dialog. |
| **COPYENGINE_S_PENDING** | Error has been queued and will display later. Operation on this file will be skipped. |