# ITfThreadMgr::AssociateFocus

## Description

Associates the focus for a window with a document manager object.

## Parameters

### `hwnd` [in]

Handle of the window to associate the focus with.

### `pdimNew` [in]

Pointer to the document manager to associate the focus with. The TSF manager does not increment the object reference count. This value can be **NULL**.

### `ppdimPrev` [out]

Receives the document manager previously associated with the window. Receives **NULL** if there is no previous association. This parameter cannot be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

This method is provided as a convenience to the application developer. Associating the focus for a window with a document manager causes the TSF manager to automatically call [ITfThreadMgr::SetFocus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-setfocus) with the associated document manager when the associated window receives the focus.

This method can only associate a single window with a single document manager. If the implementation associates multiple document managers with a single window, or the opposite, the implementation must call **ITfThreadMgr::SetFocus** to set the focus to the proper document manager.

To restore the previous focus association, call this method with the same window handle and the value returned in the original call *ppdimPrev* for *pdimNew*. The following is an example.

```cpp

//associate the focus for m_hwnd with m_pDocMgr
pThreadMgr->AssociateFocus(m_hwnd, m_pDocMgr, &m_pPrevDocMgr);

//Restore the original focus association.
ITfDocumentMgr *pTempDocMgr = NULL;

pThreadMgr->AssociateFocus(m_hwnd, m_pPrevDocMgr, &pTempDocMgr);

if(pTempDocMgr)
{
    pTempDocMgr->Release();
}

if(m_pPrevDocMgr)
{
    m_pPrevDocMgr->Release();
}

```

## See also

[ITfDocumentMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfdocumentmgr)

[ITfThreadMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfthreadmgr)

[ITfThreadMgr::SetFocus](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfthreadmgr-setfocus)