# ITextPara::Reset

## Description

Resets the paragraph formatting to a choice of default values.

## Parameters

### `Value` [in]

Type: **long**

Type of reset. It can be one of the following possible values.

| Value | Meaning |
| --- | --- |
| [tomDefault](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) | Used for paragraph formatting that is defined by the RTF \pard, that is, the paragraph default control word. |
| [tomUndefined](https://learn.microsoft.com/windows/win32/api/tom/ne-tom-tomconstants) | Used for all undefined values. The tomUndefined value is only valid for duplicate (clone) [ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara) objects. |

## Return value

Type: **HRESULT**

If **ITextPara::Reset** succeeds, it returns **S_OK**. If the method fails, it returns one of the following COM error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **Value** | Meaning |
| **E_ACCESSDENIED** | Write access is denied. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **CO_E_RELEASED** | The paragraph formatting object is attached to a range that has been deleted. |

## See also

**Conceptual**

[ITextPara](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextpara)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)