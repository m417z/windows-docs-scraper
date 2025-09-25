# MMC_TASK structure

## Description

The
**MMC_TASK** structure is introduced in MMC 1.1.

The
**MMC_TASK** structure is filled in by the
[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next) method to specify all the data required to set up an individual task on a taskpad.

## Members

### `sDisplayObject`

[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object) structure that the snap-in must fill in to specify the image to be displayed as the image for the task in the taskpad specified by **pszGroup**.

### `szText`

A pointer to a null-terminated string that contains the text placed directly to the right of the mouse-over image. This text serves as the label for the task. This text should be an action in the imperative such as "Add a new user."

### `szHelpString`

A pointer to a null-terminated string that contains the descriptive text placed in the upper-right corner when the user moves the mouse over the mouse-over image or the label text for the task. This text serves as the description for the task such as "Creates a new account, creates a mailbox, and sets up everything a user must access the network."

### `eActionType`

Value of type
[MMC_ACTION_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_action_type) that specifies the type of action triggered when a user clicks a task on a taskpad.

There are three types of actions:

#### MMC_ACTION_ID

When the user clicks the task, MMC calls
[IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify) and returns the command ID specified in the **nCommandID** member. If you specify this value, the **nCommandID** member is required.

#### MMC_ACTION_LINK

When the user clicks the task, MMC activates the link specified by **szActionURL**. If you specify this value, the **szActionURL** member is required.

#### MMC_ACTION_SCRIPT

When the user clicks the task, MMC executes the script contained in **szScript** using the [window.execScript](https://learn.microsoft.com/previous-versions/hh869591(v=vs.85)) method on the taskpad DHTML page. If you specify this value, the **zScript** member is required.

### `nCommandID`

Used only if **eActionType** is **MMC_ACTION_ID**.

A value that specifies the command ID returned to the snap-in when the user clicks the task.

When MMC calls [IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify), it passes in the *arg* parameter a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure that contains the command ID for the task that was clicked on the taskpad. The **vt** field is **VT_I4** and the **lVal** field contains the command ID.

### `szActionURL`

Used only if eActionType is **MMC_ACTION_LINK**.

[out] A pointer to a null-terminated string that contains the URL to which the task links. The URL must be fully qualified. The string can also contain a script instead of a URL.

### `szScript`

Used only if **eActionType** is **MMC_ACTION_SCRIPT**.

[out] A pointer to a null-terminated string that contains the script to run using the [window.execScript](https://learn.microsoft.com/previous-versions/hh869591(v=vs.85)) method on the taskpad DHTML page. To specify the script language, begin the string with the script language:

* "VBSCRIPT:"
* "JSCRIPT:"
* "JAVASCRIPT:"

If no script language is specified, the default language is JavaScript.

## Remarks

Allocate the **szText**, **szHelpString**, **szActionURL**,and **szScript** strings used in the structure with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release them.

You should also allocate the strings in the
[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap) or
[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol) structure specified in the **sDisplayObject** member with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release them.

## See also

[IEnumTASK::Next](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-ienumtask-next)

[IExtendTaskPad::TaskNotify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendtaskpad-tasknotify)

[MMC_ACTION_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_action_type)

[MMC_TASK_DISPLAY_BITMAP](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_bitmap)

[MMC_TASK_DISPLAY_OBJECT](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_object)

[MMC_TASK_DISPLAY_SYMBOL](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_task_display_symbol)