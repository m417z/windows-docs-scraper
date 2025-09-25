# GetPointerCursorId function

## Description

Retrieves the cursor identifier associated with the specified pointer.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve the cursor identifier.

### `cursorId` [out]

An address of a **UINT32** to receive the tablet cursor identifier, if any, associated with the specified pointer.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Cursor objects represent pointing and selecting devices used with digitizer devices, most commonly tactile contacts on touch digitizers and tablet pens on pen digitizers. Physical pens may have multiple tips (such as normal and eraser ends), with each pen tip representing a different cursor object. Each cursor object has an associated cursor identifier.

For pointer types that derive from these cursor objects, an application can use the **GetPointerCursorId** function to retrieve the cursor identifier associated with a pointer.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)