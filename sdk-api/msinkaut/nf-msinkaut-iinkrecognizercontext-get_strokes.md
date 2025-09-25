# IInkRecognizerContext::get_Strokes

## Description

Gets or sets the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection associated with the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object.

This property is read/write.

## Parameters

## Remarks

You can set the [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection more than once. Each time you set the InkStrokes collection, the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object is reset-any ink or results are removed and any prior calls to the [EndInkInput Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-endinkinput) method are disregarded-and then the new strokes are added.

The [InkStrokes](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85)) collection can also be set to **NULL**, which also resets the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object. When the **InkRecognizerContext** is reset, it keeps any guides, factoids, and other properties which previously had been set on it.

When the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object is reset, any recognition taking place on the background thread is canceled.

To keep the **Strokes** property of the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object synchronized with an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object, use the [InkAdded](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkadded) and [InkDeleted](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkdeleted) events of the **InkDisp** object to listen for strokes that should be added or removed from the **InkRecognizerContext** object. This covers cases where strokes are added to, deleted from, clipped, or split within the **InkDisp** object.

**Note** Moving, scaling, or other transformations on strokes in the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object do not generate [InkAdded](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkadded) or [InkDeleted](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-inkdeleted) events. Perform the same transformations on the strokes in the [InkRecognizerContext](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class) object to keep the **Strokes** property of the **InkRecognizerContext** object synchronized.

## See also

[IInkRecognizerContext](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrecognizercontext)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))