# IInkRecognizerContext::get_Factoid

## Description

Gets or sets the factoid that a recognizer uses to constrain its search for the recognition result.

This property is read/write.

## Parameters

## Remarks

A factoid provides recognizer context for recognized ink in the context of a particular field. You specify a factoid if an input field is of a known type, for example, if the input field contains a date.

For more information about factoids and how to use them, see [Improving Tablet PC Recognition Accuracy by Setting Context](https://learn.microsoft.com/windows/desktop/tablet/using-context-to-improve-accuracy).

Setting the **Factoid** succeeds only if the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection is **NULL**. You must set the **Factoid** before you attach the InkStrokes collection to the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) or you must set the Strokes collection to **NULL** and then set the **Factoid** (and possibly reattach the InkStrokes collection).

To ensure that ink is recognized in the correct field context, set this property before processing the ink for the first time, such as before calling the [Recognize](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-recognize) method.

**Note** All factoids are case sensitive.

This property takes or returns a string parameter and not a class object of the [Factoid](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants) class. The members of this class are of type **string**.

For the [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control, this property should only be changed if the [Status](https://learn.microsoft.com/windows/desktop/api/inked/nf-inked-iinkedit-get_status) property returns [IES_Idle](https://learn.microsoft.com/windows/desktop/api/inked/ne-inked-inkeditstatus).

## See also

[Factoid Constants](https://learn.microsoft.com/windows/desktop/tablet/factoid-constants)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)