# IWICDevelopRaw::QueryRawCapabilitiesInfo

## Description

Retrieves information about which capabilities are supported for a raw image.

## Parameters

### `pInfo` [out]

Type: **[WICRawCapabilitiesInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrawcapabilitiesinfo)***

A pointer that receives [WICRawCapabilitiesInfo](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicrawcapabilitiesinfo) that provides the capabilities supported by the raw image.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that a codec report that a capability is supported even if the results at the outer range limits are not of perfect quality.