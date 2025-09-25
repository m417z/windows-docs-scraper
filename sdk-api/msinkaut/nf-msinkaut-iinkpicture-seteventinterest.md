# IInkPicture::SetEventInterest

## Description

Modifies a value that indicates whether an object or control has interest in a specified event.

## Parameters

### `EventId` [in]

The event to be listened for. Possible values for *eventID* appear in the [InkCollectorEventInterest](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectoreventinterest) enumeration type.

### `Listen` [in]

**VARIANT_TRUE** to indicate the event is being used; **VARIANT_FALSE** to indicate the event is being ignored.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid event interest. |
| **E_INK_EXCEPTION** | An exception occurred during processing. |

## Remarks

All ink collector events can be toggled by using this method. Most of these events are turned off by default for performance reasons. The only events that are on by default are [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-stroke), [CursorInRange](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-cursorinrange), and [CursorOutOfRange](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-cursoroutofrange).

Use the [NewPackets](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-newpackets), [NewInAirPackets](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-newinairpackets) and [CursorDown](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-cursordown) events carefully, in particular because they may have an adverse effect on ink performance if too much code is executed in the event handlers.

## See also

[CursorDown Event](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-cursordown)

[CursorInRange Event](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-cursorinrange)

[GetEventInterest Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-geteventinterest)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkCollectorEventInterest Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkcollectoreventinterest)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[NewPackets Event](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-newpackets)

[Stroke Event](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-stroke)