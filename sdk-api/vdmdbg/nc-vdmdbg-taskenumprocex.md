# TASKENUMPROCEX callback function

## Description

[This function is not supported and may be altered or unavailable in the future.]

Implement this function to receive information for each task that [VDMEnumTaskWOWEx](https://learn.microsoft.com/windows/desktop/api/vdmdbg/nf-vdmdbg-vdmenumtaskwowex) enumerates.

The **TASKENUMPROCEX** type defines a pointer to this callback function. **ProcessTasks** is a placeholder for the application-defined function name.

## Parameters

### `dwThreadId` [out]

The thread ID.

### `hMod16` [out]

The module handle.

### `hTask16` [out]

The task handle.

### `pszModName` [out]

The module name.

### `pszFileName` [out]

The file name.

### `lpUserDefined` [out]

The user-defined data that was passed to the [VDMEnumTaskWOWEx](https://learn.microsoft.com/windows/desktop/api/vdmdbg/nf-vdmdbg-vdmenumtaskwowex) function.

## Return value

Return **TRUE** to stop the enumeration and **FALSE** to continue.

## Remarks

You can use the value of the *hTask16* parameter in a call to terminate the task.