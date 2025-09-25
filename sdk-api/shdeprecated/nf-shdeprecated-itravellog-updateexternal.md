# ITravelLog::UpdateExternal

## Description

Deprecated. Updates an entry that originated out of the current procedure through [IHlinkFrame](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa767938(v=vs.85)).

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) representing the nearest browser or frame within which the travel generating the log is taking place.

### `punkHLBrowseContext` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of an [IHlinkBrowseContext](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa767949(v=vs.85)) retrieved through [IHlinkFrame::GetBrowseContext](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa767937(v=vs.85)).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.