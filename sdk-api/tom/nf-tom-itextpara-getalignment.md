# ITextPara::GetAlignment

## Description

Retrieves the current paragraph alignment value.

## Parameters

### `pValue`

Type: **long***

The paragraph alignment, which can be one of the following values.

#### tomAlignLeft

#### tomAlignCenter

#### tomAlignRight

#### tomAlignJustify

#### tomAlignInterWord

#### tomAlignNewspaper

#### tomAlignInterLetter

#### tomAlignScaled

## Return value

Type: **HRESULT**

If **ITextPara::GetAlignment** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_INVALIDARG** | The *pValue* parameter is null. |
| **CO_E_RELEASED** | The paragraph format object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[SetAlignment](https://learn.microsoft.com/windows/desktop/api/tom/nf-tom-itextpara-setalignment)

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)