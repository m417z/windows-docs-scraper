# IMediaRendererFactory::streaming

## Description

Asynchronously creates a new instance of an object that implements the [IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer) interface using the specified Unique Device Name (UDN).

## Parameters

### `deviceIdentifier` [in]

An HSTRING containing a UDN that identifies the DLNA DMR device for which an instance of [IMediaRenderer](https://learn.microsoft.com/windows/desktop/mediastreaming/imediarenderer) will be created.

### `value` [out, retval]

Receives a reference to a [CreateMediaRendererOperation](https://learn.microsoft.com/windows/desktop/mediastreaming/createmediarendereroperation) object that is used to get results from the asynchronous operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMediaRendererFactory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828924(v=vs.85))