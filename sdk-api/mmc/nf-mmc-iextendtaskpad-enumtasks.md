# IExtendTaskPad::EnumTasks

## Description

The **IExtendTaskPad::EnumTasks** method enables MMC to get a pointer to the
IEnumTASK interface of the object that contains the snap-in's tasks.

## Parameters

### `pdo` [in]

A pointer to the data object for the scope item that owns the taskpad.

### `szTaskGroup` [in]

A pointer to a null-terminated string that contains the group name that identifies the taskpad. The group name is the string that follows the hash (#) in the string passed in the ppViewType parameter when MMC calls [IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) to display the taskpad. If no group name is specified, szTaskGroup is a **NULL** string.

### `ppEnumTASK` [out]

A pointer to address of
IEnumTASK interface of the object that contains the snap-in's tasks.

## Return value

This method can return one of these values.

## Remarks

MMC calls this method each time a taskpad from the snap-in is displayed. MMC also calls the method if the snap-in extends another snap-in's taskpad in order to get a pointer to the snap-in's
IEnumTASK interface.

## See also

[IEnumTASK](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ienumtask)

[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad)