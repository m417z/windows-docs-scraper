# IOfflineFilesProgress::QueryAbort

## Description

May be called during lengthy operations to determine if the operation should be canceled.

## Parameters

### `pbAbort` [out]

Set this value to **TRUE** to cancel the operation. Set to **FALSE** to continue.

## Return value

The return value is ignored.

## Remarks

This method may be used by the implementation in cases where calls to other progress methods are infrequent. The sole purpose of this method is to determine if the operation should be canceled immediately.

## See also

[IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress)