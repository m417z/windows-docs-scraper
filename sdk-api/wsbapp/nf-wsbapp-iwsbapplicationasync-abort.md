# IWsbApplicationAsync::Abort

## Description

Cancels an incomplete asynchronous operation.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Windows Server Backup calls this method to cancel an asynchronous operation. For example, if the overall backup operation is canceled while an asynchronous consistency-check operation is in progress, this method will be called to cancel the consistency-check operation.

## See also

[IWsbApplicationAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationasync)