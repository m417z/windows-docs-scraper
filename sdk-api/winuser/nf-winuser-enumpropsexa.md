# EnumPropsExA function

## Description

Enumerates all entries in the property list of a window by passing them, one by one, to the specified callback function. **EnumPropsEx** continues until the last entry is enumerated or the callback function returns **FALSE**.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose property list is to be enumerated.

### `lpEnumFunc` [in]

Type: **PROPENUMPROCEX**

A pointer to the callback function. For more information about the callback function, see the [PropEnumProcEx](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-propenumprocexa) function.

### `lParam` [in]

Type: **LPARAM**

Application-defined data to be passed to the callback function.

## Return value

Type: **int**

The return value specifies the last value returned by the callback function. It is -1 if the function did not find a property for enumeration.

## Remarks

An application can remove only those properties it has added. It must not remove properties added by other applications or by the system itself.

#### Examples

For an example, see [Listing Window Properties for a Given Window](https://learn.microsoft.com/windows/desktop/winmsg/using-window-properties).

> [!NOTE]
> The winuser.h header defines EnumPropsEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[PropEnumProcEx](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-propenumprocexa)

**Reference**

[Window Properties](https://learn.microsoft.com/windows/desktop/winmsg/window-properties)