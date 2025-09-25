# IResultData2::RenameResultItem

## Description

The
**RenameResultItem** method programmatically places the specified result item into rename mode, after which, the user can manually enter the new name. This method is designed specifically for the case where an item is created and immediately must be placed into rename mode. Use of this method under other scenarios, such as being called after an item has been selected, is not supported and may have unexpected results.

## Parameters

### `itemID` [in]

The result item being placed into rename mode. When applied to virtual lists, pass the item index instead of the result item.

## Return value

If successful, the return value is S_OK; otherwise, the return value is an error code. The [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and/or [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros can be used to evaluate the return value. If the Rename verb is not enabled, this method returns E_FAIL.

## Remarks

The item being placed into rename mode must have the Rename verb enabled for this method to succeed.

## See also

[IConsole3::RenameScopeItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsole3-renamescopeitem)