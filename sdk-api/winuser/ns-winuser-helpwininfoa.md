# HELPWININFOA structure

## Description

Contains the size and position of either a primary or secondary Help window. An application can set this information by calling the [WinHelp](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-winhelpa) function with the HELP_SETWINPOS value.

## Members

### `wStructSize`

Type: **int**

The size of this structure, in bytes.

### `x`

Type: **int**

X-coordinate of the upper-left corner of the window, in screen coordinates.

### `y`

Type: **int**

Y-coordinate of the upper-left corner of the window, in screen coordinates.

### `dx`

Type: **int**

The width of the window, in pixels.

### `dy`

Type: **int**

The height of the window, in pixels.

### `wMax`

Type: **int**

Options for display of the window. It can be any of the values that can be specified in the *nCmdShow* parameter for the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) function.

### `rgchMember`

Type: **TCHAR[2]**

The name of the window.

## Remarks

Windows Help divides the display into 1024 units in both the X and Y directions. To create a secondary window that fills the upper-left quadrant of the display, for example, an application would specify zero for the **x** and **y** members and 512 for the **dx** and **dy** members.

To calculate **wStructSize** properly, the actual size of the string to be stored at **rgchMember** must be known. Since [sizeof](https://learn.microsoft.com/previous-versions/0w557fh7(v=vs.85))(HELPWININFO) includes two **TCHARs** by definition, they must be taken into account in the final total. The following example shows the proper calculation of an instance of **wStructSize**.

```
WORD wSize;
TCHAR *szWndName = TEXT("wnd_menu");
size_t NameLength;
HRESULT hr;
HELPWININFO hwi;

// StringCbLength returns the length of the string without
// the terminating null character.
hr = StringCbLength(szWndName, STRSAFE_MAX_CCH * sizeof(TCHAR), &NameLength);

if (SUCCEEDED(hr))
{
    // Add bytes to account for the name string's terminating null character.
    NameLength + sizeof(TCHAR);

    // Determine the size of HELPWININFO without the TCHAR array.
    wSize = sizeof(HELPWININFO) - (2 * sizeof(TCHAR));

    // Determine the total size of the final HELPWININFO structure.
    hwi.wStructSize = wSize + NameLength;
}
```

> [!NOTE]
> The winuser.h header defines HELPWININFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).