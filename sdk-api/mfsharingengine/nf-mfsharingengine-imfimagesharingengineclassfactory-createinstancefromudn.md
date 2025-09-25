# IMFImageSharingEngineClassFactory::CreateInstanceFromUDN

## Description

Creates an instance of the [IMFImageSharingEngine](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfimagesharingengine) from the provided unique device name.

## Parameters

### `pUniqueDeviceName`

The unique device name of the device with which the sharing engine is created.

### `ppEngine` [out]

Receives a pointer to the [IMFImageSharingEngine](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfimagesharingengine) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFImageSharingEngineClassFactory](https://learn.microsoft.com/windows/desktop/api/mfsharingengine/nn-mfsharingengine-imfimagesharingengineclassfactory)