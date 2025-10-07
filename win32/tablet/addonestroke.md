# AddOneStroke function

Adds a new [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object that was passed in.

This function is not intended to be used by application code.

## Parameters

*hDivider* \[in\]

A handle to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*strokeId* \[in\]

The [**Id**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokedisp-get_id) of the [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object to be added to the [**InkDivider**](https://learn.microsoft.com/windows/win32/tablet/inkdivider-class) object.

*cPoints* \[in\]

The number of packets that make up the new [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object.

*aPoints* \[in\]

The array of packets that make up the [**IInkStrokeDisp**](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object in *strokeId*.

## Return value

This function can return one of these values.

| Return code | Description |
|----------------------------------------------------------------------------------------------|-------------------------------------------------|
| **S\_OK** | The function succeeded.<br> |
| **E\_INVALIDARG** | The *hDivider* parameter is invalid.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Library<br> | InkDiv.dll |

