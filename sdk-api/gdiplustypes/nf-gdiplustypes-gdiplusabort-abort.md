## Description

**Abort** is an application-defined method that is called periodically by Windows GDI+ during time-consuming rendering operations. See the [**GdiplusAbort**](https://learn.microsoft.com/windows/win32/api/gdiplustypes/ns-gdiplustypes-gdiplusabort) structure.

## Parameters

### `unnamedParam1`

Type: **[VOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**Abort** doesn't take any parameters.

## Return value

Return **S_OK** for GDI+ to continue the rendering operation. Return **E_ABORT** for GDI+ to abort the rendering operation.

## Remarks

## See also

[GdiplusAbort](https://learn.microsoft.com/windows/win32/api/gdiplustypes/ns-gdiplustypes-gdiplusabort)