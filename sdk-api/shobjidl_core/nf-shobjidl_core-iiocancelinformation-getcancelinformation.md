# IIOCancelInformation::GetCancelInformation

## Description

Returns information that is posted when a user selects **Cancel** from the progress UI. The process thread uses this method to find out which message the progress dialog will send to the process thread when the user hits cancel. The process thread then listens for this message and does its own cleanup upon receipt.

## Parameters

### `pdwThreadID` [out]

Type: **DWORD***

When this method returns, contains a pointer to the ID of the process thread.

### `puMsgCancel` [out]

Type: **UINT***

When this method returns, contains a pointer to *uMsgCancel* that the process thread should post if the operation is canceled.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.