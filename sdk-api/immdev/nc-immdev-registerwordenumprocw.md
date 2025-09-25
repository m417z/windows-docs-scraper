## Description

An application-defined callback function used with the [ImmEnumRegisterWord](https://learn.microsoft.com/windows/win32/api/imm/nf-imm-immenumregisterworda) function. It is used to process data of register strings. The REGISTERWORDENUMPROC type defines a pointer to this callback function. **EnumRegisterWordProc** is a placeholder for the application-defined function name.

## Parameters

### `lpszReading` [in]

Pointer to a null-terminated string specifying the matched reading string.

### `unnamedParam2` [in]

The style of the register string.

### `lpszString` [in]

Pointer to a null-terminated string specifying the matched register string.

### `unnamedParam4` [in]

Application-supplied data.

## Return value

Returns a nonzero value to continue enumeration, or 0 to stop enumeration.

## Remarks

An application must register this function by passing its address to the [ImmEnumRegisterWord](https://learn.microsoft.com/windows/win32/api/imm/nf-imm-immenumregisterworda) function.

> [!NOTE]
> The immdev.h header defines REGISTERWORDENUMPROC as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ImmEnumRegisterWord](https://learn.microsoft.com/windows/win32/api/imm/nf-imm-immenumregisterworda)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)