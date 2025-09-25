# IExtendTaskPad::TaskNotify

## Description

The **IExtendTaskPad::TaskNotify** method enables MMC to notify the snap-in when a task is extended. If the taskpad is a list-view taskpad, MMC also calls **IExtendTaskPad::TaskNotify** when a list-view button is extended.

## Parameters

### `pdo` [in]

A pointer to the data object for the scope item that owns the taskpad. If your snap-in owns the item that displays the taskpad, pdo is a pointer to that item. If your snap-in is extending the taskpad of another snap-in, pdo is a pointer to the item in the snap-in that owns the taskpad.

### `arg` [in]

A pointer to a VARIANT structure that contains information passed back from the CIC control on the taskpad.

Taskpads using MMC taskpad templates

For the MMC-supplied taskpads, the VARIANT structure contains the command ID for the taskpad task or list-view button that was ed.

The vt field is VT_I4 and the lVal field contains the command ID for the taskpad task or list-view button that was ed. List-view buttons apply only to list-view taskpads.

A task command ID is specified in the nCommandID member of the
[MMC_TASK](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task) structure, which is passed in the [IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next) method that MMC calls when it retrieves the information for that task during the setup of the taskpad.

A list-view button is the button specified in the szButtonText member of the
[MMC_LISTPAD_INFO](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_listpad_info) structure, which is passed in the [IExtendTaskPad::GetListPadInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-getlistpadinfo) method that MMC calls when it is setting up the list-view taskpad. The list-view button command ID is specified in the nCommandID member of
MMC_LISTPAD_INFO.

Taskpads using custom HTML pages

For custom taskpads, the VARIANT structure can contain any data that the script on the custom HTML page wants to pass through the CIC object
TaskNotify method

### `param` [in]

A pointer to a VARIANT structure that contains information passed back from the CIC control on the taskpad.

Taskpads that use the MMC taskpad templates ignore this parameter. However, custom taskpads can use it to pass an additional value back to the snap-in.

## Return value

This method can return one of these values.

## Remarks

The snap-in can identify the scope item that owns the taskpad using the pdo pointer; it then can identify the task by the VARIANT value returned in the arg parameter. If the taskpad is a list-view taskpad, the snap-in can identify the selected item (or items if multiselection is supported) in a result list using the
[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata) interface. Based on this data, the snap-in can perform the appropriate actions on the appropriate object.

If a taskpad list-view button is ed for a list-view taskpad, the snap-in can identify the button for the particular taskpad by the VARIANT value returned in the arg parameter.

A custom taskpad can pass any values that it determines should be sent in the arg and param parameters.

## See also

[IEnumTASK](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-ienumtask)

[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad)