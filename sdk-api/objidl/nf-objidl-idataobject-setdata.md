# IDataObject::SetData

## Description

Called by an object containing a data source to transfer data to the object that implements this method.

## Parameters

### `pformatetc` [in]

A pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure defining the format used by the data object when interpreting the data contained in the storage medium.

### `pmedium` [in]

A pointer to the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure defining the storage medium in which the data is being passed.

### `fRelease` [in]

If **TRUE**, the data object called, which implements **SetData**, owns the storage medium after the call returns. This means it must free the medium after it has been used by calling the [ReleaseStgMedium](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-releasestgmedium) function. If **FALSE**, the caller retains ownership of the storage medium and the data object called uses the storage medium for the duration of the call only.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DV_E_LINDEX** | Invalid value for **lindex**; currently, only -1 is supported. |
| **DV_E_FORMATETC** | The value for *pformatetc* is not valid. |
| **DV_E_TYMED** | The **tymed** value is not valid. |
| **DV_E_DVASPECT** | The **dwAspect** value is not valid. |
| **OLE_E_NOTRUNNING** | The object application is not running. |
| **E_FAIL** | The operation failed. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *dwDirection* value is not valid. |
| **E_OUTOFMEMORY** | There was insufficient memory available for this operation. |

## Remarks

**SetData** allows another object to attempt to send data to the implementing data object. A data object implements this method if it supports receiving data from another object. If it does not support this, it should be implemented to return E_NOTIMPL.

The caller allocates the storage medium indicated by the *pmedium* parameter, in which the data is passed. The data object called does not take ownership of the data until it has successfully received it and no error code is returned. The value of the *fRelease* parameter indicates the ownership of the medium after the call returns. **FALSE** indicates the caller still owns the medium, and the data object only has the use of it during the call; **TRUE** indicates that the data object now owns it and must release it when it is no longer needed.

The type of medium specified in the *pformatetc* and *pmedium* parameters must be the same. For example, one cannot be a global handle and the other a stream.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)