# IInkPicture::GetGestureStatus

## Description

Retrieves a value that indicates whether the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control has interest in a particular application gesture.

## Parameters

### `Gesture` [in]

The gesture that you want the status of.

### `Listening` [out, retval]

**VARIANT_TRUE** if the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control has interest in the gesture and the [Gesture Event](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-gesture) fires when the gesture is recognized. **VARIANT_FALSE** if the InkPicture control has no interest in the gesture, and the strokes that were recognized as a gesture remain as [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) objects.

## Return value

This method can return one of these values.

| HRESULT value | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_INVALID_MODE** | Collection mode must be in gesture-mode. |
| **E_OUTOFMEMORY** | Cannot allocate memory to perform action. |
| **E_INK_EXCEPTION** | An exception occurred. |
| **E_INVALIDARG** | The flag is invalid. |

## Remarks

This method throws an exception if the *gesture* parameter is set to [IAG_AllGestures](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture).

To set the interest of the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control in a particular gesture, call the [SetGestureStatus Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setgesturestatus).

**Note** By default, the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control does not have interest in any application gesture.

## See also

[Gesture Event](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-gesture)

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkApplicationGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)

[InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SetGestureStatus Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-setgesturestatus)