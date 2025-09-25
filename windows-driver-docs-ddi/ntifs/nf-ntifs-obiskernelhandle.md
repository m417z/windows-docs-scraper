# ObIsKernelHandle function

## Description

The **ObIsKernelHandle** routine determines whether the specified handle is a kernel handle.

## Parameters

### `Handle` [in]

The handle to check.

## Return value

**ObIsKernelHandle** returns **TRUE** if *Handle* is a kernel handle and **FALSE** otherwise.

## Remarks

You can use kernel handles only in kernel mode. A driver can mark a handle as a kernel handle by specifying the OBJ_KERNEL_HANDLE flag in [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) when it creates the handle.

**Note** **ObIsKernelHandle** does not verify that the parameter is a valid handle. This routine only determines if a valid handle is a kernel handle. If the parameter is not a valid handle, the result of the routine is undefined.

## See also

[OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes)