# ITextDocument::GetName

## Description

Gets the file name of this document. This is the [ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument) default property.

## Parameters

### `pName`

Type: **BSTR***

The file name.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **S_FALSE** | No file name associated with this object. |
| **E_INVALIDARG** | Invalid argument. |
| **E_OUTOFMEMORY** | Insufficient memory for output string. |

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)