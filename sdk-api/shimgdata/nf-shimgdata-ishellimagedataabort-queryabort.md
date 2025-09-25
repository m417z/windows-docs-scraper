# IShellImageDataAbort::QueryAbort

## Description

Aborts an [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) process such as [Decode](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-decode), [Draw](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-draw), or [Scale](https://learn.microsoft.com/windows/desktop/api/shimgdata/nf-shimgdata-ishellimagedata-scale). This is a callback method.

## Return value

Type: **HRESULT**

Returns S_OK if the [IShellImageData](https://learn.microsoft.com/windows/desktop/api/shimgdata/nn-shimgdata-ishellimagedata) process should continue, or S_FALSE if it should be aborted.