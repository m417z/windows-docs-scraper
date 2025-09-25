# IInkCollector::GetGestureStatus

## Description

Indicates whether the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) or [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object is interested in a particular application gesture.

## Parameters

### `Gesture` [in]

Sets the gesture that you want the status of.

### `Listening` [out, retval]

**VARIANT_TRUE** if the InkCollector control has interest in a particular application gesture; otherwise, **VARIANT_VALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_INVALID_MODE** | Collection mode must be in gesture-mode. |
| **E_OUTOFMEMORY** | Cannot allocate memory to perform action. |
| **E_INK_EXCEPTION** | An exception occurred. |
| **E_INVALIDARG** | The flag is invalid. |

## Remarks

This method throws an exception if the gesture parameter is set to [IAG_AllGestures](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture).

To set the interest of the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) or [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object in a particular gesture, call the **InkCollector** or **InkOverlay** object's [SetGestureStatus](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setgesturestatus) method.

**Note** By default, the [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) and [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) objects do not have interest in any of the application gestures.

## See also

[Gesture Event](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture)

[IInkCollector](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkcollector)

[InkApplicationGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[SetGestureStatus Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setgesturestatus)