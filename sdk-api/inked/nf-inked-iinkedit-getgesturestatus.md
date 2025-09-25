# IInkEdit::GetGestureStatus

## Description

Indicates whether the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control is interested in a particular application gesture.

## Parameters

### `Gesture` [in]

The gesture that you want the status of.

### `pListen` [out, retval]

**VARIANT_TRUE** if the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control has interest in the gesture and the [Gesture](https://learn.microsoft.com/windows/desktop/tablet/inkedit-gesture) event of the InkEdit control fires when the gesture is recognized. **VARIANT_FALSE** if the InkEdit control has no interest in the gesture.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | Input parameter was incorrect. |
| **E_INK_INVALID_MODE** | Collection mode must be in gesture-mode. |
| **E_OUTOFMEMORY** | Cannot allocate memory to perform action. |
| **E_INK_EXCEPTION** | An exception occurred. |
| **E_INVALIDARG** | The flag is invalid. |

## Remarks

This method throws an exception if the *gesture* parameter is set to the [IAG_AllGestures](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) gesture.

To set the interest of the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control in a particular gesture, call the [SetGestureStatus](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-setgesturestatus) method.

**Note** By default, the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control has interest in the following gestures:

* [IAG_Left](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)
* [IAG_Right](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)
* [IAG_UpRightLong](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)
* [IAG_DownLeftLong](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)
* [IAG_UpRight](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)
* [IAG_DownLeft](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)

## See also

[Gesture Event [InkEdit Control]](https://learn.microsoft.com/windows/desktop/tablet/inkedit-gesture)

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkApplicationGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)

[SetGestureStatus Method [InkEdit Control]](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-setgesturestatus)