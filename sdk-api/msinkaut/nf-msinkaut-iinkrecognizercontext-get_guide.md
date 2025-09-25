# IInkRecognizerContext::get_Guide

## Description

Gets or sets the [InkRecognizerGuide](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class) to use for ink input.

This property is read/write.

## Parameters

## Remarks

Setting the **Guide** property succeeds only if the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection is **NULL**. You must set the **Guide** property before you attach the InkStrokes collection to the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) or you must set the InkStrokes collection to **NULL** and then set the **Guide** (and possible reattach the InkStrokes collection).

The [InkRecognizerCapabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities) enumeration contains the **IRC_FreeInput**, **IRC_LinedInput**, and **IRC_BoxedInput** flags. These flags specify the capabilities of a recognizer, but because they are read only, there is no way to set any of these directly on a [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) or [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object. The only way to put a recognizer into a specific mode is to set the guide using the **Guide** property. If you do not set the **Guide** property, the recognizer defaults to **FreeInput** mode (if the recognizer is capable of this). Another way to set the recognizer into **FreeInput** mode is to set the **Guide** property to a [InkRecognizerGuide](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class) object that has its [Columns](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns) property set to zero and its [Rows](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_rows) property set to zero.

If you set the **Guide** property to a [InkRecognizerGuide](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class) object that has its [Columns](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns) property set to zero and its [Rows](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_rows) property set to 1 or more, the recognizer is in [IRC_LinedInput](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities) mode (if the recognizer is capable of this). The recognizer uses the **Rows** property to control the number of lines.

If you set the **Guide** property to a [InkRecognizerGuide](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class) object that has its [Rows](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_rows) property set to zero and its [Columns](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns) property set to 1 or more, the recognizer is in [IRC_LinedInput](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities) mode (if the recognizer is capable of this) for vertical writing. The recognizer uses the **Columns** property to control the number of vertical lines. If the recognizer is capable of this, the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object's [Capabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizer-get_capabilities) property returns either **IRC_DownAndLeft** or **IRC_DownAndRight**, or both.

If you set the **Guide** property to a [InkRecognizerGuide](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class) object that has its [Columns](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns) property set to 1 or more and its [Rows](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_rows) property set to 1 or more, the recognizer is in [IRC_BoxedInput](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities) mode (if the recognizer is capable of this).

If you set the mode to one that is not available from this recognizer, an error is returned.

For information about how to query which capabilities, or modes, are available from a specific recognizer, see the [Capabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizer-get_capabilities) property of the [IInkRecognizer](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer) object. In general, recognizers of Latin script support free input and horizontal lined input, recognizers of East Asian characters support free input and boxed input, and the gesture recognizer only supports free input.

## See also

[Capabilities Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizer-get_capabilities)

[Columns Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_columns)

[IInkRecognizer Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkrecognizer)

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerCapabilities Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkrecognizercapabilities)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[InkRecognizerGuide Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))

[Rows Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_rows)