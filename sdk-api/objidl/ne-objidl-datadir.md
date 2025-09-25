# DATADIR enumeration

## Description

Specifies the direction of the data flow. This determines the formats that the resulting enumerator can enumerate.

## Constants

### `DATADIR_GET:1`

Requests that [IDataObject::EnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc) supply an enumerator for the formats that can be specified in[IDataObject::GetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-getdata).

### `DATADIR_SET:2`

Requests that [IDataObject::EnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc) supply an enumerator for the formats that can be specified in [IDataObject::SetData](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-setdata).

## See also

[IDataObject::EnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-enumformatetc)

[OleRegEnumFormatEtc](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleregenumformatetc)