# IMILBitmapEffectGroup::GetInteriorOutputConnector

## Description

Retrieves the output connector for an effect at the given index.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

The index of the effect to retrieve the connector.

### `ppConnector` [out, retval]

Type: **[IMILBitmapEffectInputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectinputconnector)****

A pointer that receives a pointer to the desired effects output connector.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.