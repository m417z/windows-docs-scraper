# ImmGetCandidateListW function

## Description

Retrieves a candidate list.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `deIndex` [in]

Zero-based index of the candidate list.

### `lpCandList` [out, optional]

Pointer to a [CANDIDATELIST](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidatelist) structure in which the function retrieves the candidate list.

### `dwBufLen` [in]

Size, in bytes, of the buffer to receive the candidate list. The application can specify 0 for this parameter if the function is to return the required size of the output buffer only.

## Return value

Returns the number of bytes copied to the candidate list buffer if successful. If the application has supplied 0 for the *dwBufLen* parameter, the function returns the size required for the candidate list buffer.

The function returns 0 if it does not succeed.

## See also

[CANDIDATELIST](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidatelist)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)

## Remarks

> [!NOTE]
> The immdev.h header defines ImmGetCandidateList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).