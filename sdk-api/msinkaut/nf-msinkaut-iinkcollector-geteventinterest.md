# IInkCollector::GetEventInterest

## Description

Retrieves the interest an object has in a particular event for the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) class, [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) class, or [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) class.

## Parameters

### `EventId` [in]

The event this method checks the interest of.

### `Listen` [out, retval]

**VARIANT_BOOL** if interest in the specified event has been set; otherwise, **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid event interest. |
| **E_INK_EXCEPTION** | An exception occurred during processing. |

## See also

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkCollectorEventInterest Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectoreventinterest)

[SetEventInterest Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-seteventinterest)