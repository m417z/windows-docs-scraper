# ITextRange::GetFormattedText

## Description

Gets an [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object with the specified range's formatted text.

## Parameters

### `ppRange`

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)****

The [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) object with the formatted text.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *ppRange* is null. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

This method, which amounts to an alias for the [ITextRange::GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getduplicate) method, is included to be Microsoft Visual Basic for Applications (VBA)-friendly. The method returns the formatted text in a range. If the [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) does not belong to the same Text Object Model (TOM) engine, call [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

Among the formats typically supported by [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) are **CF_TEXT** and **CF_RTF**. In addition, private formats can be used to reference a text solution's own internal rich-text formats. The following Microsoft Visual Basic example uses the **FormattedText** property to replace the text in a range2, by the formatted text in range1.

`range2.FormattedText = range1.FormattedText`

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[SetFormattedText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-setformattedtext)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)