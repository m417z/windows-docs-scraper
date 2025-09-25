# IOleLink::GetBoundSource

## Description

Retrieves a pointer to the link source if the connection is active.

## Parameters

### `ppunk` [out]

Address of [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer variable that receives the interface pointer to the link source. When successful, the implementation must call [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on *ppunk*; it is the caller's responsibility to call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the implementation sets *ppunk* to **NULL**.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The operation failed. |

## Remarks

You typically do not need to call **IOleLink::GetBoundSource**.

## See also

[IOleLink](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolelink)