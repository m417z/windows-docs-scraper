# IInkEdit::SetGestureStatus

## Description

Modifies the interest of the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control in a known application gesture.

## Parameters

### `Gesture` [in]

The [IInkGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkgesture) object that you want the status of.

### `Listen` [in]

**VARIANT_TRUE** to indicate that the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control uses the application gesture; otherwise, **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The input parameter was incorrect. |
| **E_INK_INVALID_MODE** | InkEdit status must be IES_Idle. |
| **E_INK_EXCEPTION** | An exception occurred. |
| **TPC_S_TRUNCATED** | Unsupported gesture. |
| **E_INVALIDARG** | The flag is invalid. |
| **E_OUTOFMEMORY** | Cannot allocate memory operation. |

## Remarks

The [IAG_AllGestures](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) gesture is not supported by the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control and returns an error. Passing invalid gesture identifiers does not return an error.

This method should only be called if the [Status](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_status) property returns IES_Idle.

To get the interest of the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control in a known gesture, call the [GetGestureStatus](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-getgesturestatus) method.

## See also

[Gesture Event](https://learn.microsoft.com/windows/desktop/tablet/inkedit-gesture)

[GetGestureStatus Method [InkEdit Control]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-getgesturestatus)

[IInkEdit](https://learn.microsoft.com/windows/win32/api/inked/nn-inked-iinkedit)

[InkApplicationGesture Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture)

[InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference)