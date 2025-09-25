# IEnumTASK::Next

## Description

The **IEnumTASK::Next** method enables MMC to retrieve the next task in the snap-in's list of tasks.

## Parameters

### `celt` [in]

A value that specifies the number of tasks to provide. MMC always enumerates tasks one at a time; therefore, celt is always 1.

### `rgelt` [out]

A pointer to an
[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task) structure that the snap-in fills in to represent the task to add to the taskpad. Be aware that the caller (MMC) allocates the memory for the structure.

### `pceltFetched` [out]

A pointer to a value that specifies the number of tasks returned. If the snap-in successfully returned one or more tasks, set the value to the number of tasks that were successfully returned. Because MMC always requests one task at a time (celt is always 1), pceltFetched should be set to 1 if the task was successfully returned. If the snap-in has no more tasks in its list, or if the snap-in fails to fill in the
MMC_TASK structure, set the value to 0.

## Return value

This method can return one of these values.

## Remarks

MMC calls this method to enumerate the list of tasks that the snap-in must add to the taskpad. MMC calls this method until it returns S_FALSE to indicate there are no more tasks for the snap-in to add to the taskpad.

## See also

[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad)

[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task)

[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap)

[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object)

[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol)