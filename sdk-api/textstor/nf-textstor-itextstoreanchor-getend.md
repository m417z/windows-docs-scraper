# ITextStoreAnchor::GetEnd

## Description

The **ITextStoreAnchor::GetEnd** method returns an anchor positioned at the end of the text stream.

## Parameters

### `ppaEnd` [out]

Pointer to an anchor object located at the very end of the text stream.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppaEnd* is invalid. |
| **E_NOTIMPL** | The application has not implemented this method. This is usually an indication that calculating the end position requires excessive resources. If the end position is necessary, you can use [ITextStoreAnchor::GetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-gettext) to calculate it, though this might also be a memory-intensive operation, paging in arbitrarily large amounts of memory from disk. |
| **E_OUTOFMEMORY** | The attempt to instantiate an anchor at the end of the document failed. |
| **TS_E_NOLOCK** | The caller does not have a read-only lock. |

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::GetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-gettext)