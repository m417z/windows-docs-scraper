# MFGetPluginControl function

## Description

Gets a pointer to the Microsoft Media Foundation plug-in manager.

## Parameters

### `ppPluginControl` [out]

Receives a pointer to the [IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)