# IDynamicRenderer::ReleaseCachedData

## Description

Releases specified stroke data from the temporal data held by [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)).

## Parameters

### `strokeId`

The identifier for the stroke.

## Return value

For a description of the return values, see [RealTimeStylus Classes and Interfaces](https://learn.microsoft.com/windows/desktop/tablet/realtimestylus-classes-and-interfaces).

## Remarks

This method is used only when the [IDynamicRenderer::DataCacheEnabled Property](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-get_datacacheenabled) property is set to **true**.

The **IDynamicRenderer::ReleaseCachedData Method** method enables you to release the specified stroke data from the temporal data held by the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object.

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) strokes can be placed in a cache, so they can be redrawn by calling the [IDynamicRenderer::Refresh Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-refresh) method. After the strokes are collected, release them from the cache by calling the **IDynamicRenderer::ReleaseCachedData Method** method. Generally, the release occurs in the [IStylusPlugin::CustomStylusDataAdded Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-customstylusdataadded) method.

*strokeId* cannot accept a value of less than zero.

## See also

[Draw Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-draw)

[DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85))

[IDynamicRenderer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-idynamicrenderer)