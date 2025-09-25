# ITextRange::SetFormattedText

## Description

Sets the formatted text of this range text to the formatted text of the specified range.

## Parameters

### `pRange` [in]

Type: **[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)***

The formatted text to replace this range's text.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Text is protected. |
| **E_INVALIDARG** | *pRange* is null. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

If the [ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange) does not belong to the same Text Object Model (TOM) engine, call [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

Among the formats typically supported by the [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) are CF_TEXT and CF_RTF. In addition, private formats can be used to reference a text solution's own internal rich-text formats. The following Microsoft Visual Basic example uses the **FormattedText** property to replace the text in range2 with the formatted text in range1.

`range2.FormattedText = range1.FormattedText`

## See also

**Conceptual**

[GetDuplicate](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getduplicate)

[GetFormattedText](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextrange-getformattedtext)

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)