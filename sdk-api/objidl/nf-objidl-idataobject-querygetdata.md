# IDataObject::QueryGetData

## Description

Determines whether the data object is capable of rendering the data as specified. Objects attempting a paste or drop operation can call this method before calling [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) to get an indication of whether the operation may be successful.

## Parameters

### `pformatetc` [in]

A pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure defining the format, medium, and target device to use for the query.

## Return value

This method returns S_OK on success. Other possible values include the following

| Return code | Description |
| --- | --- |
| **DV_E_LINDEX** | Invalid value for **lindex**; currently, only -1 is supported. |
| **DV_E_FORMATETC** | Invalid value for *pformatetc*. |
| **DV_E_TYMED** | The **tymed** value is not valid. |
| **DV_E_DVASPECT** | The **dwAspect** value is not valid. |
| **OLE_E_NOTRUNNING** | The object application is not running. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *dwDirection* value is not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |

## Remarks

The client of a data object calls **QueryGetData** to determine whether passing the specified [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure to a subsequent call to [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) is likely to be successful. A successful return from this method does not necessarily ensure the success of the subsequent paste or drop operation.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)