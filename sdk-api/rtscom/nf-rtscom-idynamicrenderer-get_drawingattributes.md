# IDynamicRenderer::get_DrawingAttributes

## Description

Gets or sets the **DrawingAttributes** object used by the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object.

This property is read/write.

## Parameters

## Remarks

Enables the caller to set or modify the drawing attributes for the next stroke. Device rendering should not use the dynamic renderer. The sole purpose of the dynamic renderer is to perform real time dynamic rendering as part of a user interface.

When creating an instance of the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) class, a default **DrawingAttributes** instance is created with the following standard attributes:

* Color = Black
* Width = 53 (2 pixels on a 96 dpi screen)
* Height = 1
* PenTip = Ball
* Transparency = 0
* AntiAliased = true
* FitToCurve = false
* ExtendedProperties = empty collection

Changes to this property are applied between strokes, when they are starting or ending.

If this property is changed while a user is drawing a stroke, the new drawing attributes are not applied to the current stroke, but take effect on the next stroke drawn. For example, setting this property to [IStylusPlugin::StylusDown Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-stylusdown) during an [IStylusAsyncPlugin](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusasyncplugin) implementation does not affect an active stroke.

When a **DisplaySettingsChanged** event occurs, recalculate the Width and Height properties of the **DrawingAttributes** object in a **DisplaySettingsChanged** event handler. This is necessary to account for possible dots per inch (dpi) changes that result from the **DisplaySettingsChanged** event.

The following are default values for the drawing attributes:

| Drawing Attribute | Value |
| --- | --- |
| AntiAliased | True |
| Color | Color.Black |
| FitToCurve | false |
| Height | 1 |
| IgnorePressure | False |
| PenTip | Ball |
| RasterOperation | CopyPen |
| Transparency | 0 |
| Width | 53 |

## See also

[IDynamicRenderer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-idynamicrenderer)

[IStylusPlugin Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-istylusplugin)

[StrokeBuilder Class](https://learn.microsoft.com/windows/desktop/tablet/strokebuilder-class)