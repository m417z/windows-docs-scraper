# IInkLineInfo::SetCandidate

## Description

Updates one recognition *alternate* in the recognition result list, either by replacing an existing alternate, or by adding an alternate to the list.

## Parameters

### `nCandidateNum` [in]

Zero based index of the alternate list entry to set.

### `strRecogWord` [in]

Pointer to the new alternate text.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The *nCandidateNum* index is out of range. |
| **E_OUTOFMEMORY** | Could not complete the operation. The recognition result list is not changed. |

## Remarks

The *candidate* list can only be extended by one new entry at a time, at the end of the current list. For example, if the *text ink object (tInk)* currently has ten recognition results, then setting the *nCandidateNum* parameter to 10 adds a new result to the text ink object's recognition result list.

## See also

[GetCandidate Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-getcandidate)

[IInkLineInfo](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinklineinfo)