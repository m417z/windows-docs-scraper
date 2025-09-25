# ID2D1SimplifiedGeometrySink::SetSegmentFlags

## Description

Specifies stroke and join options to be applied to new segments added to the geometry sink.

## Parameters

### `vertexFlags`

Type: **[D2D1_PATH_SEGMENT](https://learn.microsoft.com/windows/win32/api/d2d1/ne-d2d1-d2d1_path_segment)**

Stroke and join options to be applied to new segments added to the geometry sink.

## Remarks

After this method is called, the specified segment flags are applied to each segment subsequently added to the sink. The segment flags are applied to every additional segment until this method is called again and a different set of segment flags is specified.

## See also

[ID2D1SimplifiedGeometrySink](https://learn.microsoft.com/windows/win32/api/d2d1/nn-d2d1-id2d1simplifiedgeometrysink)