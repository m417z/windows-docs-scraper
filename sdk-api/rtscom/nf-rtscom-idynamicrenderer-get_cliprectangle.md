# IDynamicRenderer::get_ClipRectangle

## Description

Gets or sets the clipping rectangle for the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object.

This property is read/write.

## Parameters

## Remarks

The **ClipRectangle** property is set immediately and applies to the stroke that is being drawn. It differs from the [IDynamicRenderer::DrawingAttributes Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_drawingattributes) property, which applies to the next stroke drawn. This allows the clip rectangle to grow as the stroke is drawn.

When calling the [IDynamicRenderer::Refresh Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-refresh) from within a Paint event handler, set the **IDynamicRenderer::ClipRectangle Property** to the Paint event's rectangle.

**Note** If the **ClipRectangle** is expanded in mid-stroke, then a [IDynamicRenderer::Refresh Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-refresh) call is required in order to display the new ink. This refresh call must be made every time new ink appears in a new area; however, doing so may cause performance problems when inking in the new area.

## See also

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IDynamicRenderer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-idynamicrenderer)

[IDynamicRenderer::ClipRegion Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_clipregion)