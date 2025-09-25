# ITfFnPlayBack::Play

## Description

Causes the audio data for a range of text to be played.

## Parameters

### `pRange` [in]

Pointer to an [ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange) object that covers the text to play the audio data for. This range object is obtained by calling [ITfFnPlayBack::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnplayback-queryrange).

If the range has zero length, the range played is expanded to cover the entire spoken phrase. If the range has a nonzero length, the range played is expanded to include the entire word, or words, that the range partially covers.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |

## See also

[ITfFnPlayBack](https://learn.microsoft.com/windows/desktop/api/ctffunc/nn-ctffunc-itffnplayback)

[ITfFnPlayBack::QueryRange](https://learn.microsoft.com/windows/desktop/api/ctffunc/nf-ctffunc-itffnplayback-queryrange)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)