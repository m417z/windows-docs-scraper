# TfCandidateResult enumeration

## Description

Elements of the **TfCandidateResult** enumeration are used with the [ITfCandidateList::SetResult](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itfcandidatelist-setresult) method to specify the result of a reconversion operation performed on a given candidate string.

## Constants

### `CAND_FINALIZED:0`

The candidate string has been selected and accepted. The previous text should be replaced with the specified candidate.

### `CAND_SELECTED:0x1`

The candidate string has been selected, but the selection is not yet final.

### `CAND_CANCELED:0x2`

The reconversion operation has been canceled.

## See also

[ITfCandidateList::SetResult](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itfcandidatelist-setresult)