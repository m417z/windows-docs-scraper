# IMILBitmapEffectInputConnector::GetConnection

## Description

Gets the [IMILBitmapEffectOutputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectoutputconnector) the input connector is connected to.

## Parameters

### `ppConnector` [out, retval]

Type: **[IMILBitmapEffectOutputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectoutputconnector)****

A pointer that receives a pointer to the associated output connector.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.