# ImmGetCandidateListCountA function

## Description

Retrieves the size of the candidate lists.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lpdwListCount` [out]

Pointer to the buffer in which this function retrieves the size of the candidate lists.

## Return value

Returns the number of bytes required for all candidate lists if successful, or 0 otherwise.

## Remarks

Applications typically call this function in response to an [IMN_OPENCANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-opencandidate) or [IMN_CHANGECANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-changecandidate) command.

> [!NOTE]
> The immdev.h header defines ImmGetCandidateListCount as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[IMN_CHANGECANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-changecandidate)

[IMN_OPENCANDIDATE](https://learn.microsoft.com/windows/desktop/Intl/imn-opencandidate)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)