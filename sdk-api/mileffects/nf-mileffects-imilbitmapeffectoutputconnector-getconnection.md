# IMILBitmapEffectOutputConnector::GetConnection

## Description

Gets the [IMILBitmapEffectInputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectinputconnector) associated with the output connector.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

The index of the desired input connector.

### `ppConnection` [out, retval]

Type: **[IMILBitmapEffectInputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectinputconnector)****

A pointer that receives a pointer to the associated input connector.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.