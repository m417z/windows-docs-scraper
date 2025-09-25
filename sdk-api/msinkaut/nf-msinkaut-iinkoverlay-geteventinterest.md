# IInkOverlay::GetEventInterest

## Description

Retrieves the interest an object has in a particular event for the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) class, [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) class, or [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) class.

## Parameters

### `EventId` [in]

The event in which the ink collector is or is not interested.

### `Listen` [out, retval]

**VARIANT_TRUE** if interest in the specified event has been set; otherwise, **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid event interest. |
| **E_INK_EXCEPTION** | An exception occurred during processing. |

## See also

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkCollectorEventInterest Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectoreventinterest)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[SetEventInterest Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-seteventinterest)