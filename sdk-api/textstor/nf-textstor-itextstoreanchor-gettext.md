# ITextStoreAnchor::GetText

## Description

The **ITextStoreAnchor::GetText** method returns information about text at a specified anchor position. This method returns the visible and hidden text and indicates if embedded data is attached to the text.

## Parameters

### `dwFlags` [in]

Not used; should be zero.

### `paStart` [in]

Specifies the starting anchor position.

### `paEnd` [in]

Specifies the ending anchor position. If **NULL**, it is treated as if it were an anchor positioned at the very end of the text stream.

### `pchText` [out]

Specifies the buffer to receive the text. May be **NULL** only when *cchReq* = 0.

### `cchReq` [in]

Specifies the *pchText* buffer size in characters.

### `pcch` [out]

Receives the number of characters copied into the *pchText* buffer.

### `fUpdateAnchor` [in]

If **TRUE**, *paStart* will be repositioned just past the last character copied to *pchText*.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method was unable to obtain a valid interface pointer to *paStart* and/or *paEnd*. |
| **TF_E_INVALIDPOS** | The *paStart* or *paEnd* anchors are outside of the document text. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock on the document. |

## Remarks

Callers that use this method must have a read-only lock on the document by calling the [ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock) method. Without a read-only lock, the method fails and returns [TF_E_NOLOCK](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values).

Applications can truncate the method return values for internal reasons.

To quickly scan text with multiple **GetText** calls, a caller would use *fUpdateAnchor* = **TRUE**.

The actual number of characters copied could be less than *cchReq* if the number of characters between *paStart* and *paEnd* is less than *cchReq.*

The behavior of **GetText** is not affected by any region boundaries covered by the returned text.

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-requestlock)

[Manager Return Values](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values)

[TS_RUNINFO](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_runinfo)