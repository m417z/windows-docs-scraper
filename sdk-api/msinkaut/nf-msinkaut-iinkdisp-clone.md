# IInkDisp::Clone

## Description

Creates a duplicate [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Parameters

### `NewInk` [out, retval]

When this method returns, contains a pointer to the newly created [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **REGDB_CLASSNOTREG** | The [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object was not registered. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

The **Clone** method is defined for the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class), [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class), and [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) objects. The **Clone** method returns an exact copy of the original object.

In most scenarios, the duplicate object is an exact copy of the original object, but no relation between the two objects exists. See the remarks section of this topic for details on exceptions to this.

[InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object: The only scenario in which the duplicate **InkDisp** object is not an exact copy of the original object is when a dirty **InkDisp** object is cloned. In this case, the duplicate **InkDisp** object's [Dirty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-get_dirty) property is **FALSE**. All other properties of the cloned **InkDisp** object are exact copies.

## See also

[Dirty Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-get_dirty)

[IInkDisp](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdisp)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[ModifyDrawingAttributes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-modifydrawingattributes)