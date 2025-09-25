# IInkOverlay::get_Ink

## Description

Gets or sets the [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object that is associated with an [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object or an [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object.

This property is read/write.

## Parameters

## Remarks

**Note** The [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) object or the [InkOverlay](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class) object must be disabled before setting this property. To disable the **InkCollector** object or the **InkOverlay** object, set the [Enabled](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled) property to **FALSE**. You can then set the [Ink](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_ink) property, and re-enable the object by setting the **Enabled** property to **TRUE**.

An [InkCollector](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class) creates an [InkDisp](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class) object by default. If two or more **InkDisp** objects exist on a known application window, they can be switched out to enable collection into any of them (such as after deserializing one of the **InkDisp** objects).

## See also

[Enabled Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-get_enabled)

[IInkOverlay](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkoverlay)

[InkDisp Class](https://learn.microsoft.com/windows/desktop/tablet/inkdisp-class)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)