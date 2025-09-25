# LockResource function

## Description

Retrieves a pointer to the specified resource in memory.

## Parameters

### `hResData` [in]

Type: **HGLOBAL**

A handle to the resource to be accessed. The [LoadResource function](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource) returns this handle. Note that this parameter is listed as an **HGLOBAL** variable only for backward compatibility. Do not pass any value as a parameter other than a successful return value from the **LoadResource** function.

## Return value

Type: **LPVOID**

If the loaded resource is available, the return value is a pointer to the first byte of the resource; otherwise, it is **NULL**.

## Remarks

The pointer returned by **LockResource** is valid until the module containing the resource is unloaded. It is not necessary to unlock resources because the system automatically deletes them when the process that created them terminates.

Do not try to lock a resource by using the handle returned by the [FindResourceA function](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea) or [FindResourceExA function](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa) function. Such a handle points to random data.

> [!Note]
> **LockResource** does not actually lock memory; it is just used to obtain a pointer to the memory containing the resource data. The name of the function comes from versions prior to Windows XP, when it was used to lock a global memory block allocated by [LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource).

#### Examples

For an example, see [Updating Resources](https://learn.microsoft.com/windows/win32/menurc/using-resources#updating-resources).

## See also

### Conceptual

- [Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

### Reference

- [Menus and Other Resources](https://learn.microsoft.com/windows/win32/api/_menurc/)
- [FindResourceA function](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourcea)
= [FindResourceExA function](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-findresourceexa)
- [LoadResource function](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource)