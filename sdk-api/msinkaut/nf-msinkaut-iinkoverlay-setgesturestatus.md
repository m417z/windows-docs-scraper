# IInkOverlay::SetGestureStatus

## Description

Sets the interest of the object or control in a known gesture.

## Parameters

### `Gesture` [in]

The gesture that you want to set the status of.

### `Listen` [in]

**VARIANT_TRUE** if the gesture is being used or **VARIANT_FALSE** if it is being ignored.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_INVALID_MODE** | InkCollector collection mode must be in gesture mode. |
| **E_INK_EXCEPTION** | An exception occurred. |
| **TPC_S_TRUNCATED** | Unsupported gesture. |
| **E_INVALIDARG** | The flag is invalid. |
| **E_OUTOFMEMORY** | Cannot allocate memory operation. |

## Remarks

To get the interest of the object or control in a known gesture, call the [GetGestureStatus](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-getgesturestatus) method.

The [IAG_AllGestures](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) gesture ID is not supported by the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control and returns an error. Passing invalid Gesture IDs does not return an error for InkEdit, but fails for [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class), [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class), and [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference).

For the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control, this method should only be called if the [Status](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_status) property returns [IES_Idle](https://learn.microsoft.com/windows/desktop/api/inked/ne-inked-inkeditstatus).

## See also

[Gesture Event](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-gesture)

[GetGestureStatus Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-getgesturestatus)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkApplicationGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)