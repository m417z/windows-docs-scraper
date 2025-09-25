# PROCESSENUMPROC callback function

## Description

[This function is not supported and may be altered or unavailable in the future.]

Implement this function to receive information for each virtual DOS machine (VDM) that [VDMEnumProcessWOW](https://learn.microsoft.com/windows/desktop/api/vdmdbg/nf-vdmdbg-vdmenumprocesswow) enumerates.

The **PROCESSENUMPROC** type defines a pointer to this callback function. **ProcessVDMs** is a placeholder for the application-defined function name.

## Parameters

### `dwProcessId` [out]

The process ID of the NTVDM.exe process. Use this ID when calling other VDM debug functions.

### `dwAttributes` [out]

The process attributes.

### `lpUserDefined` [out]

The user-defined data that was passed to the [VDMEnumProcessWOW](https://learn.microsoft.com/windows/desktop/api/vdmdbg/nf-vdmdbg-vdmenumprocesswow) function.

## Return value

Return **TRUE** to stop the enumeration and **FALSE** to continue.