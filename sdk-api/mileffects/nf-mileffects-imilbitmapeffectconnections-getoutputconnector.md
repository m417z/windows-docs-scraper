# IMILBitmapEffectConnections::GetOutputConnector

## Description

Retrieves the output connector associated with the given pin index.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating which output pin to use to retrieve the output connector.

### `ppConnector` [out, retval]

Type: **[IMILBitmapEffectOutputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectoutputconnector)****

When this method returns, contains the output connector for the given output pin.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.