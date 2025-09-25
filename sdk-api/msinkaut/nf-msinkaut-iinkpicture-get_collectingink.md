# IInkPicture::get_CollectingInk

## Description

Gets a value that specifies whether ink is currently being drawn on an ink collector ([InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class), [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class), or [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)).

This property is read-only.

## Parameters

## Remarks

You can use the **CollectingInk** property to see if ink is being drawn on an ink collector rather than monitoring the [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-stroke) event.

**Note** Because ink collection is happening on a different thread than your application code, it is possible that the **CollectingInk** property can change soon after you have checked it. Thus, your code may be operating under the assumption that the ink collector is not collecting ink, when in fact it is. If this occurs, an error is thrown. To be safe, put such code in a try-catch block.

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)