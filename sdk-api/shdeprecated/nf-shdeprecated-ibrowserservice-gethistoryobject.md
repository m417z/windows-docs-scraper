# IBrowserService::GetHistoryObject

## Description

Deprecated. Retrieves an [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) that represents the browser's history object.

## Parameters

### `ppole` [out]

Type: **[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)****

The address of a pointer to an [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) that represents the browser's history object.

### `pstm` [out]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)****

The address of a pointer to the history object's [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream). This parameter may be **NULL**.

### `ppbc` [out]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)****

The address of a pointer to the history object stream's [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx). This parameter may be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If *pstm* is not **NULL**, you can call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) to get a pointer to [IPersistHistory](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768215(v=vs.85)).

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) and [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) can be passed to [IPersistHistory::LoadHistory](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768216(v=vs.85)).

The calling application must release all three pointers if non-**NULL**.