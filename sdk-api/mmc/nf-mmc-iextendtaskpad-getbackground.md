# IExtendTaskPad::GetBackground

## Description

The **IExtendTaskPad::GetBackground** method enables MMC to get the taskpad's background image to display in taskpads that use MMC taskpad templates.

## Parameters

### `pszGroup` [in]

A pointer to a null-terminated string that contains the group name that identifies the taskpad. The group name is the string that follows the hash (#) in the string passed in the ppViewType parameter when MMC calls IComponent::GetResultViewType to display the taskpad. If no group name is specified, pszGroup is a **NULL** string.

### `pTDO` [out]

A pointer to an
[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure that the snap-in must fill in to specify the image to be displayed as the background for the taskpad specified by pszGroup.

Be aware that the caller (MMC) allocates the memory for the
MMC_TASK_DISPLAY_OBJECT structure.

## Return value

This method can return one of these values.

## Remarks

Allocate the strings in the
[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap) or
[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol) structure specified in the pTDO parameter with the COM API function CoTaskMemAlloc (or the equivalent) and MMC will release it.

## See also

[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad)

[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap)

[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object)

[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol)