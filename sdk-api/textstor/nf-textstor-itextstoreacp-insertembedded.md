# ITextStoreACP::InsertEmbedded

## Description

Inserts an embedded object at the specified character.

## Parameters

### `dwFlags` [in]

Must be TS_IE_CORRECTION.

### `acpStart` [in]

Contains the starting character position where the object is inserted.

### `acpEnd` [in]

Contains the ending character position where the object is inserted.

### `pDataObject` [in]

Pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface that contains data about the object inserted.

### `pChange` [out]

Pointer to a [TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange) structure that receives data about the modified text.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_NOTIMPL** | The application does not support embedded objects. |
| **TS_E_FORMAT** | The application does not support the data type contained in *pDataObject*. |
| **TS_E_INVALIDPOS** | *acpStart* and/or *acpEnd* are not within the document. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock. |

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[TS_IE_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-ie--constants)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)