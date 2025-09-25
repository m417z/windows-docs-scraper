# ITextStoreACP2::GetText

## Description

Gets info about text at a specified character position. This method returns the visible and hidden text and indicates if embedded data is attached to the text.

## Parameters

### `acpStart` [in]

Specifies the starting character position.

### `acpEnd` [in]

Specifies the ending character position. If this parameter is -1, then return all text in the text store.

### `pchPlain` [out]

Specifies the buffer to receive the plain text data. If this parameter is **NULL**, then the *cchPlainReq* parameter must be 0.

### `cchPlainReq` [in]

Specifies the number of plain text characters passed to the method.

### `pcchPlainRet` [out]

Receives the number of characters copied into the plain text buffer. This parameter cannot be **NULL**. Use a parameter if values are not required.

### `prgRunInfo` [out]

Receives an array of [TS_RUNINFO](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_runinfo) structures. May be **NULL** only if *cRunInfoReq* = 0.

### `cRunInfoReq` [in]

Specifies the size, in characters, of the text run buffer.

### `pcRunInfoRet` [out]

Receives the number of **TS_RUNINFO** structures written to the text run buffer. This parameter cannot be **NULL**.

### `pacpNext` [out]

Receives the character position of the next unread character. Cannot be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_INVALIDPOS** | The *acpStart* or *acpEnd* parameters are outside of the document text. |
| **TF_E_NOLOCK** | The caller does not have a read-only lock on the document. |

## Remarks

Callers that use this method must have a read-only lock on the document by calling the [RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-requestlock) method. Without a read-only lock, the method fails and returns [TF_E_NOLOCK](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values).

Applications can also truncate the method return values for internal reasons. Callers should carefully examine the return characters and text run counts to get the required return values. If the return values are incomplete, repeatedly call the method until the return values are complete.

The caller can request plain text only by setting the *cRunInfoReq* parameter to 0 and the *prgRunInfo* parameter to **NULL**. The caller can request only text run data by setting the *cchPlainReq* parameter to 0 and the *pchPlain* parameter to **NULL**. However, the caller must still supply valid non-**null** values for *pcchPlainRet*, even if this parameter is not used.

If *acpEnd* is -1, then it should be handled as if set at the end of the stream. Otherwise, it will be greater than or equal to zero.

On exit, *pacpNext* should be set to the character position of the next character in the stream not referenced by the return values. A caller would use this to quickly scan text with multiple **GetText** calls.

## See also

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[Manager Return Values](https://learn.microsoft.com/windows/desktop/TSF/manager-return-values)

[RequestLock](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-requestlock)

[TS_RUNINFO](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_runinfo)