# IDataObject::GetCanonicalFormatEtc

## Description

Provides a potentially different but logically equivalent [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure. You use this method to determine whether two different **FORMATETC** structures would return the same data, removing the need for duplicate rendering.

## Parameters

### `pformatectIn` [in]

A pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that defines the format, medium, and target device that the caller would like to use to retrieve data in a subsequent call such as [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata). The **tymed** member is not significant in this case and should be ignored.

### `pformatetcOut` [out]

A pointer to a [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that contains the most general information possible for a specific rendering, making it canonically equivalent to *pformatetcIn*. The caller must allocate this structure and the **GetCanonicalFormatEtc** method must fill in the data. To retrieve data in a subsequent call like [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata), the caller uses the specified value of *pformatetcOut*, unless the value specified is **NULL**. This value is **NULL** if the method returns DATA_S_SAMEFORMATETC. The **tymed** member is not significant in this case and should be ignored.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The returned [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure is different from the one that was passed. |
| **DATA_S_SAMEFORMATETC** | The [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures are the same and **NULL** is returned in *pformatetcOut*. |
| **DV_E_LINDEX** | The value for **lindex** is not valid; currently, only -1 is supported. |
| **DV_E_FORMATETC** | The value for *pformatetc* is not valid. |
| **OLE_E_NOTRUNNING** | The object application is not running. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_INVALIDARG** | The *dwDirection* parameter is not valid. |
| **E_OUTOFMEMORY** | There was insufficient memory available for this operation. |

## Remarks

If a data object can supply exactly the same data for more than one requested [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure, **GetCanonicalFormatEtc** can supply a "canonical", or standard **FORMATETC** that gives the same rendering as a set of more complicated **FORMATETC** structures. For example, it is common for the data returned to be insensitive to the target device specified in any one of a set of otherwise similar **FORMATETC** structures.

### Notes to Callers

A call to this method can determine whether two calls to [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) on a data object, specifying two different [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures, would actually produce the same renderings, thus eliminating the need for the second call and improving performance. If the call to **GetCanonicalFormatEtc** results in a canonical format being written to the *pformatetcOut* parameter, the caller then uses that structure in a subsequent call to **IDataObject::GetData**.

### Notes to Implementers

Conceptually, it is possible to think of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures in groups defined by a canonical **FORMATETC** that provides the same results as each of the group members. In constructing the canonical **FORMATETC**, you should make sure it contains the most general information possible that still produces a specific rendering.

For data objects that never provide device-specific renderings, the simplest implementation of this method is to copy the input [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) to the output **FORMATETC**, store a **NULL** in the **ptd** member of the output **FORMATETC**, and return DATA_S_SAMEFORMATETC.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)