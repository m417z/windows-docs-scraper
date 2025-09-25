# IDWriteTextLayout::GetClusterMetrics

## Description

 Retrieves logical properties and measurements of each glyph cluster.

## Parameters

### `clusterMetrics` [out, optional]

Type: **[DWRITE_CLUSTER_METRICS](https://learn.microsoft.com/windows/win32/api/dwrite/ns-dwrite-dwrite_cluster_metrics)***

When this method returns, contains metrics, such as line-break or total advance width, for a glyph cluster.

### `maxClusterCount`

Type: **UINT32**

The maximum size of the *clusterMetrics* array.

### `actualClusterCount` [out]

Type: **UINT32***

When this method returns, contains the actual size of the *clusterMetrics* array that is needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 If *maxClusterCount* is not large enough, then E_NOT_SUFFICIENT_BUFFER, which is equivalent to HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER), is
returned and *actualClusterCount* is set to the number of clusters
needed.

## See also

[IDWriteTextLayout](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritetextlayout)