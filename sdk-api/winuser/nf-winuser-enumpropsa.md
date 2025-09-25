# EnumPropsA function

## Description

Enumerates all entries in the property list of a window by passing them, one by one, to the specified callback function. **EnumProps** continues until the last entry is enumerated or the callback function returns **FALSE**.

To pass application-defined data to the callback function, use [EnumPropsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumpropsexa) function.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose property list is to be enumerated.

### `lpEnumFunc` [in]

Type: **PROPENUMPROC**

A pointer to the callback function. For more information about the callback function, see the [PropEnumProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-propenumproca) function.

## Return value

Type: **int**

The return value specifies the last value returned by the callback function. It is -1 if the function did not find a property for enumeration.

## Remarks

An application can remove only those properties it has added. It must not remove properties added by other applications or by the system itself.

> [!NOTE]
> The winuser.h header defines EnumProps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[EnumPropsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumpropsexa)

[PropEnumProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-propenumproca)

**Reference**

[Window Properties](https://learn.microsoft.com/windows/desktop/winmsg/window-properties)