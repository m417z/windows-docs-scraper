# IInkPicture::get_Ink

## Description

Gets or sets the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object that is associated with the [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control.

This property is read/write.

## Parameters

## Remarks

**Note** The [InkPicture](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference) control must be disabled before setting this property. To disable inking in the InkPicture control, set the [InkEnabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkpicture-get_inkenabled) property to **FALSE**. You can then set the **Ink** property, and re-enable the control by setting the **InkEnabled** property to **TRUE**.

For further details about this property, refer to the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object's [Ink](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkoverlay-get_ink) property, which has the same functionality.

## See also

[IInkPicture](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkpicture)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkPicture Control](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control)