# ImmGetCandidateWindow function

## Description

Retrieves information about the candidates window.

## Parameters

### `HIMC` [in]

Handle to the input context.

### `DWORD` [in]

Index of the candidates window.

### `lpCandidate` [out]

Pointer to a [CANDIDATEFORM](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidateform) structure in which this function retrieves information about the candidates window.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## See also

[CANDIDATEFORM](https://learn.microsoft.com/windows/desktop/api/imm/ns-imm-candidateform)

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)