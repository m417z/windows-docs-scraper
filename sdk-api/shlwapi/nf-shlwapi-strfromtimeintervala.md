# StrFromTimeIntervalA function

## Description

Converts a time interval, specified in milliseconds, to a string.

## Parameters

### `pszOut` [out]

Type: **PTSTR**

A pointer to a buffer that, when this function returns successfully, receives the converted number.

### `cchMax`

Type: **UINT**

The size of *pszOut*, in characters. If *cchMax* is set to zero, **StrFromTimeInterval** will return the minimum size of the character buffer needed to hold the converted string. In this case, *pszOut* will not contain the converted string.

### `dwTimeMS`

Type: **DWORD**

The time interval, in milliseconds.

### `digits`

Type: **int**

The maximum number of significant digits to be represented in *pszOut*. Some examples are:

| dwTimeMS | digits | pszOut |
| --- | --- | --- |
| 34000 | 3 | 34 sec |
| 34000 | 2 | 34 sec |
| 34000 | 1 | 30 sec |
| 74000 | 3 | 1 min 14 sec |
| 74000 | 2 | 1 min 10 sec |
| 74000 | 1 | 1 min |

## Return value

Type: **int**

Returns the number of characters in *pszOut*, excluding the terminating **NULL** character.

## Remarks

The time value returned in *pszOut* will always be in the form *hh* hours *mm* minutes *ss* seconds. Times that exceed twenty four hours are not converted to days or months. Fractions of seconds are ignored.

#### Examples

```cpp
#include <windows.h>
#include <iostream.h>
#include "Shlwapi.h"

void main(void)
{
    char TimeString[256];
    char *pszOut;
    pszOut = TimeString;

    cout << "The return value from the call to"
         << "\nthe function StrFromTimeInterval will"
         << "\nreturn the number of elements in the buffer: " << endl;

    cout << "\nThe return from StrFromTimeInterval is "
         << StrFromTimeInterval(pszOut,30, 34000,30);

    cout << "\nThe contents of the TimeString Buffer " << pszOut << endl;

    cout << "The return from StrFromTimeInterval is "
         << StrFromTimeInterval(pszOut,30, 74000,3);

    cout << "\nThe contents of the TimeString Buffer " << pszOut << endl;

    cout << "The return from StrFromTimeInterval is "
         << StrFromTimeInterval(pszOut,30, 74000,2);

    cout << "\nThe contents of the TimeString Buffer " << pszOut << endl;

    cout << "The return from StrFromTimeInterval is "
         << StrFromTimeInterval(pszOut,30, 74000,1)
         << "\nThe contents of the TimeString Buffer " << pszOut << endl;
}

OUTPUT:
- - - - -
The return value from the call to
the function StrFromTimeInterval will
return the number of elements in the buffer:

The return from StrFromTimeInterval is 7
The contents of the TimeString Buffer  34 sec
The return from StrFromTimeInterval is 13
The contents of the TimeString Buffer  1 min 14 sec
The return from StrFromTimeInterval is 13
The contents of the TimeString Buffer  1 min 10 sec
The return from StrFromTimeInterval is 6
The contents of the TimeString Buffer  1 min
```

> [!NOTE]
> The shlwapi.h header defines StrFromTimeInterval as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).