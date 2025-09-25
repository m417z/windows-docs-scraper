# IConsole3::RenameScopeItem

## Description

The
**RenameScopeItem** method programmatically puts the specified scope item in rename mode. Subsequently, the user can manually enter the new name.

Use this method only when an item is created and immediately must be put in rename mode. Use of this method for other scenarios, such as being called after an item has been selected, is not supported and may have unexpected results.

## Parameters

### `hScopeItem` [in]

The scope item put in rename mode.

## Return value

If successful, the return value is **S_OK**. If unsuccessful, the method returns **E_FAIL**.

## Remarks

For this method to succeed, the item put in rename mode must have the Rename verb enabled, and the scope pane must be not be invisible.

## See also

[IConsole3](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole3)

[IResultData2::RenameResultItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata2-renameresultitem)