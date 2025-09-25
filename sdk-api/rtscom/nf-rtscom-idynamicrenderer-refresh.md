# IDynamicRenderer::Refresh

## Description

Causes the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object to redraw the ink data that is currently rendering.

## Return value

This method can return one of these values.

## Remarks

If the [IDynamicRenderer::DataCacheEnabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_datacacheenabled) property is **true**, then the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object redraws all tablet stylus data not yet released from the cache. If the **IDynamicRenderer::DataCacheEnabled Property** property is **false**, then the **DynamicRenderer Class** object redraws only the current stroke.

When calling the **IDynamicRenderer::Refresh Method** from within a Paint event handler, set the [IDynamicRenderer::ClipRectangle Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_cliprectangle) to the Paint event's rectangle.

## See also

[Draw Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-draw)

[IDynamicRenderer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-idynamicrenderer)

[IDynamicRenderer::DrawingAttributes Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_drawingattributes)