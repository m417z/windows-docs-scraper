## Description

> [!Note]
>This function is obsolete and is only supported for backward compatibility with 16-bit Windows. For 32-bit Windows applications, it is not necessary to free the resources loaded using [LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource). For modern versions of Windows this function always returns **FALSE**.

Decrements (decreases by one) the reference count of a loaded resource. When the reference count reaches zero, the memory occupied by the resource is freed.

## Parameters

### `hResData` [in]

Type: **HGLOBAL**

A handle of the resource. It is assumed that *hglbResource* was created by [LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource).

## Return value

Type: **BOOL**

If the function succeeds, the return value is zero.

If the function fails, the return value is nonzero, which indicates that the resource has not been freed.

## Remarks

For resources loaded with other functions, **FreeResource** has been replaced by the following functions:

| Resource type | FreeResource replacement |
| --- | --- |
| Accelerator | [DestroyAcceleratorTable](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyacceleratortable) |
| Bitmap | [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) |
| Cursor | [DestroyCursor](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroycursor) |
| Icon | [DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon) |
| Menu | [DestroyMenu](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroymenu) |

The reference count for a resource is incremented (increased by one) each time an application calls the [LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource) function for the resource.

The system automatically deletes these resources when the process that created them terminates. However, calling the appropriate function saves memory. For more information, see [LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource).

## See also

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[DestroyAcceleratorTable](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyacceleratortable)

[DestroyCursor](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroycursor)

[DestroyIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroyicon)

[DestroyMenu](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-destroymenu)

[LoadResource](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadresource)

**Other Resources**

**Reference**