# IDataObject::GetDataHere

## Description

Called by a data consumer to obtain data from a source data object. This method differs from the [GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) method in that the caller must allocate and free the specified storage medium.

## Parameters

### `pformatetc` [in]

A pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that defines the format, medium, and target device to use when passing the data. Only one medium can be specified in **tymed**, and only the following values are valid: TYMED_ISTORAGE, TYMED_ISTREAM, TYMED_HGLOBAL, or TYMED_FILE.

### `pmedium` [in, out]

A pointer to the [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure that defines the storage medium containing the data being transferred. The medium must be allocated by the caller and filled in by **GetDataHere**. The caller must also free the medium. The implementation of this method must always supply a value of **NULL** for the **punkForRelease** member of the **STGMEDIUM** structure to which this parameter points.

## Return value

This method returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **DV_E_LINDEX** | The value for **lindex** is not valid; currently, only -1 is supported. |
| **DV_E_FORMATETC** | The value for *pformatetc* is not valid. |
| **DV_E_TYMED** | The **tymed** value is not valid. |
| **DV_E_DVASPECT** | The **dwAspect** value is not valid. |
| **OLE_E_NOTRUNNING** | The object application is not running. |
| **STG_E_MEDIUMFULL** | An error occurred when allocating the medium. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *dwDirection* parameter is not valid. |
| **E_OUTOFMEMORY** | There was insufficient memory available for this operation. |

## Remarks

The **GetDataHere** method is similar to [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata), except that the caller must both allocate and free the medium specified in *pmedium*. **GetDataHere** renders the data described in a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure and copies the data into that caller-provided [STGMEDIUM](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-ustgmedium-r1) structure. For example, if the medium is TYMED_HGLOBAL, this method cannot resize the medium or allocate a new hGlobal.

Some media are not appropriate in a call to **GetDataHere**, including GDI types such as metafiles. The **GetDataHere** method cannot put data into a caller-provided metafile. In general, the only storage media it is necessary to support in this method are TYMED_ISTORAGE, TYMED_ISTREAM, and TYMED_FILE.

When the transfer medium is a stream, OLE makes assumptions about where the data is being returned and the position of the stream's seek pointer. In a [GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) call, the data returned is from stream position zero through just before the current seek pointer of the stream (that is, the position on exit). For **GetDataHere**, the data returned is from the stream position on entry through just before the position on exit.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)