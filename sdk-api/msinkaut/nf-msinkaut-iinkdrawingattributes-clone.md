# IInkDrawingAttributes::Clone

## Description

Creates a duplicate [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object.

## Parameters

### `DrawingAttributes` [out, retval]

When this method returns, contains a pointer to the newly created [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object.

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

The [Clone](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-clone) method is defined for the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class), [InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class), and [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) objects. The **Clone** method returns an exact copy of the original object.

In most scenarios, the duplicate object is an exact copy of the original object, but no relation between the two objects exists. See the remarks section of this topic for details on exceptions to this.

[InkDrawingAttributes](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class) object: Typically, you clone a master copy of the drawing attributes, modify one or more of the attributes, and call the [ModifyDrawingAttributes](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-modifydrawingattributes) method to use the modified drawing attributes.

## See also

[Dirty Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-get_dirty)

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[InkDrawingAttribute Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[ModifyDrawingAttributes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-modifydrawingattributes)