# ImmEscapeA function

## Description

Accesses capabilities of particular IMEs that are not available through other IME API functions. This function is used mainly for country-specific operations.

## Parameters

### `HKL` [in]

Input locale identifier.

### `HIMC` [in]

Handle to the input context.

### `UINT` [in]

Index of the operations. For more information, see [IME Escapes](https://learn.microsoft.com/windows/desktop/Intl/ime-escapes).

### `LPVOID` [in, out]

Pointer to the data required for the escape specified in *uEscape*. On output, this parameter indicates the result of the escape. For more information, see [IME Escapes](https://learn.microsoft.com/windows/desktop/Intl/ime-escapes).

## Return value

Returns an operation-specific value if successful, or 0 otherwise.

## Remarks

When *uEscape* is set to IME_ESC_QUERY_SUPPORT, *lpData* indicates the buffer containing the IME escape value. For example, to see if the current IME supports IME_ESC_GETHELPFILENAME, your application uses the following call:

```cpp
DWORD dwEsc = IME_ESC_GETHELPFILENAME;
LRESULT lRet = ImmEscape(hKL,
                         hIMC,
                         IME_ESC_QUERY_SUPPORT,
                         (LPVOID)&dwEsc);

```

> [!NOTE]
> The immdev.h header defines ImmEscape as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)