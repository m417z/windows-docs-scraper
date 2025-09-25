# ITextStoreACP2::GetFormattedText

## Description

Gets formatted text data about a specified text string. The caller must have a read/write lock on the document before calling this method.

## Parameters

### `acpStart` [in]

Specifies the starting character position of the text to get in the document.

### `acpEnd` [in]

Specifies the ending character position of the text to get in the document. This parameter is ignored if the value is 1.

### `ppDataObject` [out]

Receives the pointer to the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object that contains the formatted text.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock on the document. |

## See also

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)