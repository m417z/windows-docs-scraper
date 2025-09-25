# PDH_BROWSE_DLG_CONFIG_W structure

## Description

The
**PDH_BROWSE_DLG_CONFIG** structure is used by the
[PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa) function to configure the **Browse Performance Counters** dialog box.

## Members

### `bIncludeInstanceIndex`

If this flag is **TRUE**, the dialog box includes an index number for duplicate instance names. For example, if there are two cmd instances, the instance list will contain cmd and cmd#1. If this flag is **FALSE**, duplicate instance names will not contain an index number.

### `bSingleCounterPerAdd`

If this flag is **TRUE**, the dialog returns only one counter. If this flag is **FALSE**, the dialog can return multiple selections, and wildcard selections are permitted. Selected counters are returned as a MULTI_SZ string.

### `bSingleCounterPerDialog`

If this flag is **TRUE**, the dialog box uses an OK and Cancel button. The dialog returns when the user clicks either button. If this flag is **FALSE**, the dialog box uses an Add and Close button. The dialog box closes when the user clicks the Close button. The Add button can be clicked multiple times. The Add button overwrites the previously selected items with the currently selected items.

### `bLocalCountersOnly`

If this flag is **TRUE**, the dialog box lets the user select counters only from the local computer (the path will not contain a computer name). If this flag is **FALSE**, the user can specify a computer from which to select counters. The computer name will prefix the counter path unless the user selects **Use local computer counters**.

### `bWildCardInstances`

If this flag is **TRUE** and the user selects **All instances**, the counter path will include the wildcard character for the instance field.

If this flag is **FALSE**, and the user selects **All instances**, all the instances currently found for that object will be returned in a MULTI_SZ string.

### `bHideDetailBox`

If this flag is **TRUE**, this removes **Detail level** from the dialog box so the user cannot change the detail level of the counters displayed in the dialog box. The detail level will be fixed to the value of the **dwDefaultDetailLevel** member.

If this flag is **FALSE**, this displays **Detail level** in the dialog box, allowing the user to change the detail level of the counters displayed.

Note that the counters displayed will be those whose detail level is less than or equal to the current detail level selection. Selecting a detail level of Wizard will display all counters and objects.

### `bInitializePath`

If this flag is **TRUE**, the dialog highlights the counter and object specified in **szReturnPathBuffer** when the dialog box is first displayed, instead of using the default counter and object specified by the computer.

If this flag is **FALSE**, this selects the initial counter and object using the default counter and object information returned by the computer.

### `bDisableMachineSelection`

If this flag is **TRUE**, the user cannot select a computer from **Select counters from computer**.

If this flag is **FALSE**, the user can select a computer from **Select counters from computer**. This is the default value.
The list contains the local computer only unless you call the [PdhConnectMachine](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhconnectmachinea) to connect to other computers first.

### `bIncludeCostlyObjects`

If this flag is **TRUE**, the counters list will also contain costly data—that is, data that requires a relatively large amount of processor time or memory overhead to collect.

If this flag is **FALSE**, the list will not contain costly counters. This is the default value.

### `bShowObjectBrowser`

If this flag is **TRUE**, the dialog lists only performance objects. When the user selects an object, the dialog returns a counter path that includes the object and wildcard characters for the instance name and counter if the object is a multiple instance object. For example, if the "Process" object is selected, the dialog returns the string "\Process(*)\*". If the object is a single instance object, the path contains a wildcard character for counter only. For example, "\System\*". You can then pass the path to [PdhExpandWildCardPath](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhexpandwildcardpatha) to retrieve a list of actual paths for the object.

### `bReserved`

### `hWndOwner`

Handle of the window to own the dialog. If **NULL**, the owner is the desktop.

### `szDataSource`

Pointer to a **null**-terminated string that specifies the name of the log file from which the list of counters is retrieved. If **NULL**, the list of counters is retrieved from the local computer (or remote computer if specified).

### `szReturnPathBuffer`

Pointer to a MULTI_SZ that contains the selected counter paths.

If **bInitializePath** is **TRUE**, you can use this member to specify a counter path whose components are used to highlight entries in computer, object, counter, and instance lists when the dialog is first displayed.

### `cchReturnPathLength`

Size of the **szReturnPathBuffer** buffer, in **TCHARs**. If the callback function reallocates a new buffer, it must also update this value.

### `pCallBack`

Pointer to the callback function that processes the user's selection. For more information, see
[CounterPathCallBack](https://learn.microsoft.com/windows/desktop/api/pdh/nc-pdh-counterpathcallback).

### `dwCallBackArg`

Caller-defined value that is passed to the callback function.

### `CallBackStatus`

On entry to the callback function, this member contains the status of the path buffer. On exit, the callback function sets the status value resulting from processing.

If the buffer is too small to load the current selection, the dialog sets this value to PDH_MORE_DATA. If this value is ERROR_SUCCESS, then the **szReturnPathBuffer** member contains a valid counter path or counter path list.

If the callback function reallocates a new buffer, it should set this member to PDH_RETRY so that the dialog will try to load the buffer with the selected paths and call the callback function again.

If some other error occurred, then the callback function should return the appropriate PDH error status value.

### `dwDefaultDetailLevel`

Default detail level to show in the **Detail level** list if **bHideDetailBox** is **FALSE**. If **bHideDetailBox** is **TRUE**, the dialog uses this value to filter the displayed performance counters and objects. You can specify one of the following values:

| Detail level | Meaning |
| --- | --- |
| **PERF_DETAIL_NOVICE** | A novice user can understand the counter data. |
| **PERF_DETAIL_ADVANCED** | The counter data is provided for advanced users. |
| **PERF_DETAIL_EXPERT** | The counter data is provided for expert users. |
| **PERF_DETAIL_WIZARD** | The counter data is provided for system designers. |

### `szDialogBoxCaption`

Pointer to a **null**-terminated string that specifies the optional caption to display in the caption bar of the dialog box. If this member is **NULL**, the caption will be **Browse Performance Counters**.

## Remarks

Each time the
[Add](https://learn.microsoft.com/windows/desktop/SysMon/counters-add) button is clicked, the **szReturnPathBuffer** buffer contains the selected counter and the **pCallBack** callback function is called. The callback function should call the
[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera) function for each counter in the buffer.

## See also

[CounterPathCallBack](https://learn.microsoft.com/windows/desktop/api/pdh/nc-pdh-counterpathcallback)

[PdhAddCounter](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhaddcountera)

[PdhBrowseCounters](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhbrowsecountersa)