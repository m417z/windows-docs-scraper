# IInkDrawingAttributes::get_Transparency

## Description

Gets or sets a value that indicates the transparency value of ink.

This property is read/write.

## Parameters

## Remarks

**Note** The transparent rendering effect may be different between dynamic and static rendering. In dynamic rendering the [IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp) object is rendered as it is drawn, as it is in the [DynamicRendering](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_dynamicrendering) property, for example. In static rendering, you use the [Draw](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-draw) method of the [InkRenderer](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class) object to render the **IInkStrokeDisp** object.

## See also

[Draw Method [InkRenderer Class]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-draw)

[DrawStroke Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-drawstroke)

[DynamicRendering Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_dynamicrendering)

[IInkDrawingAttributes](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkdrawingattributes)

[InkDrawingAttributes Class](https://learn.microsoft.com/windows/desktop/tablet/inkdrawingattributes-class)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)