# IMILBitmapEffectConnectionsInfo::GetOutputConnectorInfo

## Description

Retrieves the [IMILBitmapEffectConnectorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectconnectorinfo) associated with the given output pin.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating which output pin to query for connector information.

### `ppConnectorInfo` [out]

Type: **[IMILBitmapEffectConnectorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectconnectorinfo)****

When this method returns, contain the connector information for the given output pin.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.