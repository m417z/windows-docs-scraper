# ITextRange::GetEmbeddedObject

## Description

Retrieves a pointer to the embedded object at the start of the specified range, that is, at *cpFirst*. The range must either be an insertion point or it must select only the embedded object.

## Parameters

### `ppObject`

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

The pointer to the object.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If the method fails, it returns one of the following error codes. For more information about COM error codes, see [Error Handling in COM](https://learn.microsoft.com/windows/desktop/com/error-handling-in-com).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *ppObject* is null. |
| **S_FALSE** | Failure for some other reason. |

## Remarks

If the start of this range does not have an embedded object or if the range selects more than a single object, *ppObject* is set equal to **NULL**.

## See also

**Conceptual**

[ITextRange](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextrange)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)