# IDynamicRenderer::get_DataCacheEnabled

## Description

Gets or sets a value that indicates whether data caching is enabled for the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object.

This property is read/write.

## Parameters

## Remarks

Setting the **DataCacheEnabled** property to **TRUE** enables you to manage the situation where slow processes block the output queue. When the window is invalidated after strokes are drawn by the [DynamicRenderer Class](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms701168(v=vs.85)) object, there may be a delay before the collected strokes are drawn. Place the strokes of the dynamic renderer in a cache and use the [IDynamicRenderer::Refresh Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-refresh) method to redraw the strokes.

After the strokes are collected, you must release them from the cache by calling the [IDynamicRenderer::ReleaseCachedData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-releasecacheddata) method. Use the [IStylusPlugin::CustomStylusDataAdded Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-customstylusdataadded) method to release the strokes.

It is also useful to set the **DataCacheEnabled** property to **TRUE** when you want to display strokes as they are drawn, but have no need to store the strokes after you have done something with them. In this case, store the data identifiers in the data parameter of the [IStylusPlugin::CustomStylusDataAdded Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-istylusplugin-customstylusdataadded) method, and then release the data when you no longer need the cached strokes.

If this property is **TRUE**, you must call the [IDynamicRenderer::ReleaseCachedData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-releasecacheddata) method for strokes which have been stored in the ink collecting object. If **FALSE**, you are not required to call the **IDynamicRenderer::ReleaseCachedData Method** method. The disadvantage to setting this property to **FALSE** is that any stroke data that was initially dynamically rendered but invalidated by other miscellaneous operations does not render until the stroke data reaches the ink collection object and is rendered there.

Setting this property to **FALSE** clears the cached data.

## See also

[IDynamicRenderer Interface](https://learn.microsoft.com/windows/desktop/api/rtscom/nn-rtscom-idynamicrenderer)

[IDynamicRenderer::ReleaseCachedData Method](https://learn.microsoft.com/windows/desktop/api/rtscom/nf-rtscom-idynamicrenderer-releasecacheddata)