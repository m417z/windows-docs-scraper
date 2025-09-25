# IWsbApplicationRestoreSupport::IsRollForwardSupported

## Description

Reports whether the application supports roll-forward restore.

## Parameters

### `pbRollForwardSupported` [out]

Receives **TRUE** if roll-forward restore is supported, or
**FALSE** otherwise.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

Applications that support roll-forward restore should set the value of the
*pbRollForwardSupported* parameter to **TRUE**.

## See also

[IWsbApplicationRestoreSupport](https://learn.microsoft.com/previous-versions/windows/desktop/api/wsbapp/nn-wsbapp-iwsbapplicationrestoresupport)