# ImmSetCandidateWindow function

## Description

Sets information about the candidates window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `lpCandidate` [in]

Pointer to a [CANDIDATEFORM](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidateform) structure that contains information about the candidates window.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function causes an [IMN_SETCANDIDATEPOS](https://learn.microsoft.com/windows/desktop/Intl/imn-setcandidatepos) command to be sent. Both the IME and the application call this function.

## See also

[CANDIDATEFORM](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidateform)

[IMN_SETCANDIDATEPOS](https://learn.microsoft.com/windows/desktop/Intl/imn-setcandidatepos)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)