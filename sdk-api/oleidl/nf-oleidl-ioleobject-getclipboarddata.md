# IOleObject::GetClipboardData

## Description

Retrieves a data object containing the current contents of the embedded object on which this method is called. Using the pointer to this data object, it is possible to create a new embedded object with the same data as the original.

## Parameters

### `dwReserved` [in]

This parameter is reserved and must be zero.

### `ppDataObject` [out]

Address of [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer variable that receives the interface pointer to the data object. If an error occurs, *ppDataObject* must be set to **NULL**. Each time an object receives a call to **IOleObject::GetClipboardData**, it must increase the reference count on *ppDataObject*. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it is done with *ppDataObject*.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | [GetClipboardData](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getclipboarddata) is not supported. |
| **OLE_E_NOTRUNNING** | The object is not running. |

## Remarks

You can use the **IOleObject::GetClipboardData** method to convert a linked object to an embedded object, in which case the container application would call **IOleObject::GetClipboardData** and then pass the data received to [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata). This method returns a pointer to a data object that is identical to what would have been passed to the clipboard by a standard copy operation.

### Notes to Callers

If you want a stable snapshot of the current contents of an embedded object, call **IOleObject::GetClipboardData**. Should the data change, you will need to call the function again for an updated snapshot. If you want the caller to be informed of changes that occur to the data, call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), then call [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise).

### Notes to Implementers

If you implement this function, you must return an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) pointer for an object whose data will not change.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[IOleObject::InitFromData](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-initfromdata)

[OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata)