# IInkRecognizerContext::EndInkInput

## Description

[**EndInkInput** is no longer available for use for recognizers of western languages as of Windows Vista.]

Stops adding ink to the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

After you call this method, you cannot add strokes to the context.

This method deals with partial recognition. Partial recognition is the ability of the recognizer to return results even if the application has not called **EndInkInput** (which signals to the application that all the ink has been entered). Partial recognition occurs only if the recognizer can determine that ink has been entered before a call to **EndInkInput**, and not all recognizers support this feature. Recognizers that do not support partial recognition do not return any result until **EndInkInput** is called. Calling for **EndInkInput** is optional.

Incremental recognition is the ability of the recognizer to process only a small part of the ink that has been passed to it and return a result. For example, consider that an application contains five lines of ink and uses a recognizer of Latin script. The recognizer can process only one line at a time and return a result. This process is used in the idle loop of the background processing thread.

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)