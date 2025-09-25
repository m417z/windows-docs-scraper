# ITextDocument::GetSaved

## Description

Gets a value that indicates whether changes have been made since the file was last saved.

## Parameters

### `pValue`

Type: **long***

The value **tomTrue** if no changes have been made since the file was last saved, or the value **tomFalse** if there are unsaved changes.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns the following COM error code. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |

## Remarks

To set the saved property, call the [ITextDocument::SetSaved](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-setsaved) method.

## See also

**Conceptual**

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[SetSaved](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextdocument-setsaved)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)