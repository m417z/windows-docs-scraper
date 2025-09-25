# ITfCandidateList::SetResult

## Description

Specifies the result of a reconversion operation for s specific candidate string.

## Parameters

### `nIndex` [in]

Specifies the zero-based index of the candidate string to set the result for. This parameter is ignored if *imcr* contains CAND_CANCELED.

### `imcr` [in]

Contains one of the [TfCandidateResult](https://learn.microsoft.com/windows/win32/api/ctffunc/ne-ctffunc-tfcandidateresult) values that specifies the result of the reconversion operation.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

A typical reconversion operation would include the following operations.

1. A list of candidates is obtained and displayed to the user in a dialog box.
2. When the user selects a candidate, but before the dialog box is dismissed, **ITfCandidateList::SetResult** is called with the index of the newly selected candidate and CAND_SELECTED.
3. If a different candidate is selected, **ITfCandidateList::SetResult** is called agian with the index of the newly selected candidate and CAND_SELECTED.
4. If the user chooses to accept the new candidate, **ITfCandidateList::SetResult** is called with the index of the currently selected candidate and CAND_FINALIZED.
5. If the user cancels the dialog, **ITfCandidateList::SetResult** is called with an index of zero and CAND_CANCELED.

## See also

[ITfCandidateList](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itfcandidatelist)

[TfCandidateResult](https://learn.microsoft.com/windows/win32/api/ctffunc/ne-ctffunc-tfcandidateresult)