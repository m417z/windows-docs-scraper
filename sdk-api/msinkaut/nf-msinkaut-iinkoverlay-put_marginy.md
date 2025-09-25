# IInkOverlay::put_MarginY

## Description

Gets or sets the y-axis margin around the window rectangle, in screen coordinates.

This margin provides a buffer around the edge of the ink window.

This property is read/write.

## Parameters

## Remarks

This property is most commonly used with nonintegrated tablet devices?the buffer gives users a margin of error when writing on a device that may not map 1 to 1 with the screen.

The margin is specified in screen coordinates. A positive margin extends outside the context, a negative margin extends inside the context, and a value of zero produces no margin. Ink is collected if the stroke starts within the margin. This behavior does not clip the ink. The context of the object or control is either the window input rectangle from the [GetWindowInputRectangle](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-getwindowinputrectangle) method or the client rectangle for the window.

The margin is effective only within the application's window. If the pen is applied outside the application's window, then the application loses focus and cannot collect ink.

**Note** The [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object, the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object, or the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control must be disabled before setting this property. To disable the **InkCollector** or **InkOverlay** object, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **FALSE**. To disable inking in the **InkOverlay** control, set the [InkEnabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_inkenabled) property to **FALSE**. You can then set the [MarginY](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_marginy) property, and re-enable the object or control by setting the **Enabled** property (or **InkEnabled** property) to **TRUE**.

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkEnabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_inkenabled)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[MarginX Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_marginx)