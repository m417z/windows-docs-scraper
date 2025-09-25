# ITextPara::GetListAlignment

## Description

Retrieves the kind of alignment to use for bulleted and numbered lists.

## Parameters

### `pValue`

Type: **long***

A variable that is one of the following values to indicate the kind of bullet and numbering alignment.

| Value | Meaning |
| --- | --- |
| tomAlignLeft | Text is left aligned. |
| tomAlignCenter | Text is centered in the line. |
| tomAlignRight | Text is right aligned. |

## Return value

Type: **HRESULT**

If **ITextPara::GetListAlignment** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | Invalid argument. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## Remarks

For a description of the different types of lists, see the [ITextPara::GetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttype) method.

## See also

**Conceptual**

[GetListType](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-getlisttype)

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetListAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setlistalignment)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)