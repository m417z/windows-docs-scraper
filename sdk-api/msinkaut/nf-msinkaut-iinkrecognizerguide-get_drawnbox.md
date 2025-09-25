# IInkRecognizerGuide::get_DrawnBox

## Description

Gets or sets the box that is physically drawn on the tablet's screen and in which writing takes place.

This property is read/write.

## Parameters

## Remarks

The lines of the drawn box are visual cues that specify where writing can take place. The user normally writes within the boundaries of the lines.

Another box, the writing box, is the invisible box in which writing can actually take place. It is larger than the drawn box and provides a margin of error to users if they draw ink outside the lines of the drawn box. You can use the [WritingBox](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_writingbox) property to set the writing box.

The writing box specifies the boundaries of the ink to the recognizer.The drawn box is drawn using ink space units, relative to the top left of the writing box.

## See also

[IInkRecognizerGuide](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizerguide)

[InkRecognizerGuide Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizerguide-class)

[WritingBox Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizerguide-get_writingbox)