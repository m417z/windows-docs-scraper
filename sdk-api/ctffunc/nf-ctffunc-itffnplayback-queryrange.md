# ITfFnPlayBack::QueryRange

## Description

Obtains the range of text for a word or phrase that contains audio data.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers all or part of the text that contains audio data.

### `ppNewRange` [out]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) pointer that receives a range object that covers all of the text that contains audio data. If there is no audio data for the text covered by *pRange*, this parameters receives **NULL**. In this case, the method returns S_OK, so the caller must verify that this parameter is not **NULL** before using the pointer.

### `pfPlayable` [out]

Pointer to a **BOOL** that receives zero if none of the text covered by *pRange* has any audio data or nonzero otherwise.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## Remarks

The current implementation of this method is simple. It clones *pRange*, places the clone in *ppNewRange*, sets *pfPlayable* to **TRUE** and returns S_OK.

## See also

[ITfFnPlayBack](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnplayback)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)