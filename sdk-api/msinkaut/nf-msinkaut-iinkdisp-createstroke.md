# IInkDisp::CreateStroke

## Description

Creates an [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object from an array of packet data input values.

## Parameters

### `PacketData` [in]

Specifies the array of packet data. The data is an array of Int32 values which, taken in order, form the array of points (x0, y0), (x1, y1), which is passed into the method within a Variant.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `PacketDescription` [in]

Is a reserved parameter that is currently not implemented.

### `Stroke` [out, retval]

When this method returns, contains a pointer to the newly-created stroke.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | Invalid VARIANT type (only VT_ARRAY | VT_I4 supported). |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_OUTOFMEMORY** | Cannot allocate memory to create the new stroke. |

## Remarks

The minimum and maximum values of any point in the points array are LONG_MIN and LONG_MAX, respectively. However, these points define an ink space rectangle whose maximum width or height cannot exceed LONG_MAX. Because of this, the difference between the minimum and maximum x-coordinates, or the minimum and maximum y-coordinates, cannot exceed LONG_MAX.

## See also

[CreateStrokes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-createstrokes)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)