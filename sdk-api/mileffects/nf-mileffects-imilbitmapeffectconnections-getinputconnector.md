# IMILBitmapEffectConnections::GetInputConnector

## Description

Retrieves the input connector associated with the given pin index.

## Parameters

### `uiIndex` [in]

Type: **ULONG**

A zero based index value indicating which input pin to use to retrieve the input connector.

### `ppConnector` [out, retval]

Type: **[IMILBitmapEffectInputConnector](https://learn.microsoft.com/previous-versions/windows/desktop/api/mileffects/nn-mileffects-imilbitmapeffectinputconnector)****

When this method returns, contains the input connector for the given input pin.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.