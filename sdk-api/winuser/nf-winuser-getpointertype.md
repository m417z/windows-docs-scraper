# GetPointerType function

## Description

Retrieves the pointer type for a specified pointer.

## Parameters

### `pointerId` [in]

An identifier of the pointer for which to retrieve pointer type.

### `pointerType` [out]

An address of a [POINTER_INPUT_TYPE](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type) type to receive a pointer input type.

## Return value

If the function succeeds, the return value is non-zero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application can use the **GetPointerType** function to determine the pointer type if it wishes to react differently to pointers of different types.

**Note** This function will never return with the generic [PT_POINTER](https://learn.microsoft.com/windows/win32/api/winuser/ne-winuser-tagpointer_input_type)  type.

## See also

[Functions](https://learn.microsoft.com/windows/win32/inputmsg/functions)