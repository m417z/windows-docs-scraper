# ID2D1CommandList::Close

## Description

Instructs the command list to stop accepting commands so that you can use it as an input to an effect or in a call to [ID2D1DeviceContext::DrawImage](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1commandsink-drawimage). You should call the method after it has been attached to an [ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext) and written to but before the command list is used.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| D2DERR_WRONG_STATE | Close has already been called on the command list. |

**Note** If the device context associated with the command list has an error, the command list returns the same error.

## Remarks

This method returns D2DERR_WRONG_STATE if it has already been called on the command list. If an error occurred on the device context during population, the method returns that error. Otherwise, the method returns S_OK.

If the **Close** method returns an error, any future use of the command list results in the same error.

## See also

[ID2D1CommandList](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1commandlist)