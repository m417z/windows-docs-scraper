# IInkRecognizerContext::Clone

## Description

Creates a duplicate [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

## Parameters

### `RecoContext` [out, retval]

When this method returns, contains the newly created [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

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

[InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object: This method returns a copy of the original **InkRecognizerContext** that contains the same settings as the original, but does not include the recognition results, if any. The settings that are copied include the recognition guide, character Autocomplete mode, a reference to the original [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class), and all properties that improve the recognition results, such as the [Factoid](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_factoid) property and [RecognitionFlags](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-get_recognitionflags) property.

## See also

[Dirty Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkdisp-get_dirty)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[ModifyDrawingAttributes Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkstrokes-modifydrawingattributes)