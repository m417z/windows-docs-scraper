# IExtendTaskPad::GetListPadInfo

## Description

The **IExtendTaskPad::GetListPadInfo** method is used for list-view taskpads only. It enables MMC to get the title text for the list control, the text for an optional button, and the command ID passed to
[IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) when that optional button is clicked.

## Parameters

### `pszGroup` [in]

A pointer to a null-terminated string that contains the group name that identifies the taskpad. The group name is the string that follows the hash (#) in the string passed in the ppViewType parameter when MMC calls [IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) to display the taskpad. If no group name is specified, szGroup is a **NULL** string.

### `lpListPadInfo` [out]

A pointer to an
[MMC_LISTPAD_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_listpad_info) structure that the snap-in must fill in with the title text for the list control, the text for an optional button, and the command ID passed to [IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) when that optional button is clicked.

Be aware that the caller (MMC) allocates the memory for the
[MMC_LISTPAD_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_listpad_info) structure.

## Return value

This method can return one of these values.

## Remarks

If the snap-in is not a list-view taskpad, this method is not called by MMC.

## See also

[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad)