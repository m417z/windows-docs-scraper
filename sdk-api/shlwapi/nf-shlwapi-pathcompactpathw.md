# PathCompactPathW function

## Description

Truncates a file path to fit within a given pixel width by replacing path components with ellipses.

## Parameters

### `hDC` [in]

Type: **HDC**

A handle to the device context used for font metrics. This value can be **NULL**.

### `pszPath` [in, out]

Type: **LPTSTR**

A pointer to a null-terminated string of length MAX_PATH that contains the path to be modified. On return, this buffer will contain the modified string.

### `dx` [in]

Type: **UINT**

The width, in pixels, in which the string must fit.

## Return value

Type: **BOOL**

Returns **TRUE** if the path was successfully compacted to the specified width. Returns **FALSE** on failure, or if the base portion of the path would not fit the specified width.

## Remarks

This function uses the font currently selected in *hDC* to calculate the width of the text. This function will not compact the path beyond the base file name preceded by ellipses.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

HDC hdc;  /* display DC handle to current font metrics */

void main( void )
{
// String path name 1.
char buffer_1[MAX_PATH] = "C:\\path1\\path2\\sample.txt";
char *lpStr1;
lpStr1 = buffer_1;

// String path name 2.
char buffer_2[MAX_PATH] = "C:\\path1\\path2\\sample.txt";
char *lpStr2;
lpStr2 = buffer_2;

// String path name 3.
char buffer_3[MAX_PATH] = "C:\\path1\\path2\\sample.txt";
char *lpStr3;
lpStr3 = buffer_3;

// String path name 4.
char buffer_4[MAX_PATH] = "C:\\path1\\path2\\sample.txt";
char *lpStr4;
lpStr4 = buffer_4;

// Variable to get the return from "PathCompactPath".
int retval;

cout << "The un-truncated path is                " << lpStr1 << endl;

retval = PathCompactPath(hdc,lpStr1,125);
cout << "The truncated path at 125 pixels is :   " << lpStr1 << endl;

retval = PathCompactPath(hdc,lpStr2,120);
cout << "The truncated path at 120 pixels is :   " << lpStr2 << endl;

retval = PathCompactPath(hdc,lpStr3,110);
cout << "The truncated path at 110 pixels is :   " << lpStr3 << endl;

retval = PathCompactPath(hdc,lpStr4,25);
cout << "The truncated path at  25 pixels is :   " << lpStr4 << endl;
}

OUTPUT:
===========
The un-truncated path is                C:\path1\path2\sample.txt
The truncated path at 125 pixels is :   C:\path1\...\sample.txt
The truncated path at 120 pixels is :   C:\pat...\sample.txt
The truncated path at 110 pixels is :   C:\p...\sample.txt
The truncated path at  25 pixels is :   ...\sample.txt
```

> [!NOTE]
> The shlwapi.h header defines PathCompactPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).