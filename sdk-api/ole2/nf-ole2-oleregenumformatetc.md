# OleRegEnumFormatEtc function

## Description

Creates an enumeration object that can be used to enumerate data formats that an OLE object server has registered in the system registry. An object application or object handler calls this function when it must enumerate those formats. Developers of custom DLL object applications use this function to emulate the behavior of the default object handler.

## Parameters

### `clsid` [in]

CLSID of the class whose formats are being requested.

### `dwDirection` [in]

Indicates whether to enumerate formats that can be passed to [IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata) or formats that can be passed to [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata). Possible values are taken from the enumeration [DATADIR](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-datadir).

### `ppenum` [out]

Address of [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) pointer variable that receives the interface pointer to the enumeration object.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **REGDB_E_CLASSNOTREG** | There is no CLSID registered for the class object. |
| **REGDB_E_READREGDB** | There was an error reading the registry. |
| **OLE_E_REGDB_KEY** | The DataFormats/GetSet key is missing from the registry. |

## Remarks

Object applications can ask OLE to create an enumeration object for [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures to enumerate supported data formats in one of two ways. One way is to call **OleRegEnumFormatEtc**. The other is to return OLE_S_USEREG in response to calls by the default object handler to [IDataObject::EnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc). OLE_S_USEREG instructs the default handler to call **OleRegEnumFormatEtc**. Because DLL object applications cannot return OLE_S_USEREG, they must call **OleRegEnumFormatEtc** rather than delegating the job to the object handler. With the supplied [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) pointer to the object, you can call the standard enumeration object methods to do the enumeration.

The **OleRegEnumFormatEtc** function and its sibling functions, [OleRegGetUserType](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetusertype), [OleRegGetMiscStatus](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olereggetmiscstatus), and [OleRegEnumVerbs](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumverbs), provide a way for developers of custom DLL object applications to emulate the behavior of OLE's default object handler in getting information about objects from the registry. By using these functions, you avoid the considerable work of writing your own, and the pitfalls inherent in working directly in the registry. In addition, you get future enhancements and optimizations of these functions without having to code them yourself.

## See also

[IDataObject::EnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc)

[IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc)