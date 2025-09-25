# ITextStoreACP2::GetEndACP

## Description

Gets the number of characters in a document.

## Parameters

### `pacp` [out]

Receives the character position of the last character in the document plus one.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The application has not implemented this method. This is usually an indication that calculating the end position requires excessive resources. If the end position is necessary, you can use [GetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-gettext) to calculate it, though this can also be a memory-intensive operation, paging in arbitrarily large amounts of memory from disk. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock. |

## See also

[GetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-gettext)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)