# IMediaRenderer::streaming

## Description

Queries the DMR asynchronously to determine if audio is currently muted or unmuted.

## Parameters

### `value` [out]

Receives a reference to a [GetMuteOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/getmuteoperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer)