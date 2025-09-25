# ITextDocument::GetDefaultTabStop

## Description

Gets the default tab width.

## Parameters

### `pValue`

Type: **float***

The default tab width.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If
*pValue* is **NULL**, the method fails and it returns **E_INVALIDARG**. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

## Remarks

The default tab width is used whenever no tab exists beyond the current display position. The default width is given in floating-point points.

## See also

[AddTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-addtab)

[ClearAllTabs](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-clearalltabs)

**Conceptual**

[DeleteTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-deletetab)

[GetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttab)

[GetTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettab)

[GetTabCount](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-gettabcount)

[ITextDocument](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextdocument)

**Reference**

[SetListTab](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlisttab)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)