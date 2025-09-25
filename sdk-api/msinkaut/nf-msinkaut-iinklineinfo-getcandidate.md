# IInkLineInfo::GetCandidate

## Description

Returns one recognition alternate from the recognition result list.

## Parameters

### `nCandidateNum` [in]

Zero-based index of the alternate list entry to retrieve.

### `pwcRecogWord` [out]

Buffer in which to store the selected recognition alternate. If *pwcRecogWord* is **NULL**, the method does not attempt to retrieve the recognition alternate word.

### `pcwcRecogWord` [out]

Passes the length of the *pwcRecogWord* buffer in Unicode characters, and returns the number of Unicode characters that were copied into the buffer.

### `dwFlags` [in]

Not used.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The *nCandidateNum* index is greater that the number of recognition alternates. |
| **ERROR_MORE_DATA** | The *pwcRecogWord* buffer is not large enough to accept the recognition alternate. |

## Remarks

If the *pwcRecogWord* parameter is null, the method does not attempt to retrieve the recognition alternate word, but only sets *pwcRecogWord* to the number of characters in the recognition alternate.

If the *pwcRecogWord* buffer is not large enough to contain the recognition alternate, then the *pwcRecogWord* buffer is filled with the first *pwcRecogWord* number of characters from the recognition alternate.

## See also

[IInkLineInfo](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinklineinfo)

[SetCandidate Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinklineinfo-setcandidate)