# IDynamicRenderer::Draw

## Description

Draws the cached data to the specified device context.

## Parameters

### `hDC` [in]

 The handle of the device context on which to draw.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

You can use **IDynamicRenderer::Draw Method** for tasks such as double buffering.

**Note** Drawing cached data cannot be used on Microsoft\<entity type="reg"/> Windows\<entity type="reg"/> XP Tablet PC Edition 2005 systems.

## See also

[IDynamicRenderer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-idynamicrenderer)

[IDynamicRenderer::DataCacheEnabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_datacacheenabled)

[IDynamicRenderer::DrawingAttributes Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_drawingattributes)

[IDynamicRenderer::ReleaseCachedData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-releasecacheddata)