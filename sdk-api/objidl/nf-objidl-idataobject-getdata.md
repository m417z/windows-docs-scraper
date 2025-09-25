# IDataObject::GetData

## Description

Called by a data consumer to obtain data from a source data object. The **GetData** method renders the data described in the specified [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure and transfers it through the specified [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure. The caller then assumes responsibility for releasing the **STGMEDIUM** structure.

## Parameters

### `pformatetcIn` [in]

A pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that defines the format, medium, and target device to use when passing the data. It is possible to specify more than one medium by using the Boolean OR operator, allowing the method to choose the best medium among those specified.

### `pmedium` [out]

A pointer to the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure that indicates the storage medium containing the returned data through its tymed member, and the responsibility for releasing the medium through the value of its **pUnkForRelease** member. If **pUnkForRelease** is **NULL**, the receiver of the medium is responsible for releasing it; otherwise, **pUnkForRelease** points to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) on the appropriate object so its [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method can be called. The medium must be allocated and filled in by **GetData**.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DV_E_LINDEX** | The value for **lindex** is not valid; currently, only -1 is supported. |
| **DV_E_FORMATETC** | The value for *pformatetcIn* is not valid. |
| **DV_E_TYMED** | The **tymed** value is not valid. |
| **DV_E_DVASPECT** | The **dwAspect** value is not valid. |
| **OLE_E_NOTRUNNING** | The object application is not running. |
| **STG_E_MEDIUMFULL** | An error occurred when allocating the medium. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *dwDirection* value is not valid. |
| **E_OUTOFMEMORY** | There was insufficient memory available for this operation. |

## Remarks

A data consumer calls **GetData** to retrieve data from a data object, conveyed through a storage medium (defined through the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure).

### Notes to Callers

You can specify more than one acceptable **tymed** medium with the Boolean OR operator. **GetData** must choose from the OR'd values the medium that best represents the data, do the allocation, and indicate responsibility for releasing the medium.

Data transferred across a stream extends from position zero of the stream pointer through to the position immediately before the current stream pointer (that is, the stream pointer position upon exit).

### Notes to Implementers

**GetData** must check all fields in the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure. It is important that **GetData** render the requested aspect and, if possible, use the requested medium. If the data object cannot comply with the information specified in the **FORMATETC**, the method should return DV_E_FORMATETC. If an attempt to allocate the medium fails, the method should return STG_E_MEDIUMFULL. It is important to fill in all of the fields in the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure.

Although the caller can specify more than one medium for returning the data, **GetData** can provide only one medium. If the initial transfer fails with the selected medium, this method can be implemented to try one of the other media specified before returning an error.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)