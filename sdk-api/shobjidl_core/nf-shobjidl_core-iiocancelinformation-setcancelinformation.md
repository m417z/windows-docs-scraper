# IIOCancelInformation::SetCancelInformation

## Description

Sets information that is posted when a user selects **Cancel** from the progress UI. Allows the main object to tell the progress dialog thread about the process thread so that the progress dialog can send the process thread the message id when the user clicks **Cancel**.

## Parameters

### `dwThreadID` [in]

Type: **DWORD**

The ID of the process thread to be canceled.

### `uMsgCancel` [in]

Type: **UINT**

The cancel message to be posted to the thread.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 When the user selects **Cancel** from the progress UI, the *dwThreadID* will cancel any pending or future input/output (I/O) requests. Also the *uMsgCancel* message, received from the progress dialog, will be posted to the thread to tell it to exit a wait state, if asynchronous I/O is pending.