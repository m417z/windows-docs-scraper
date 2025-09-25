# IMFMediaEngineClassFactoryEx::CreateMediaSourceExtension

## Description

Creates an instance of [IMFMediaSourceExtension](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediasourceextension).

## Parameters

### `dwFlags` [in]

This parameter is reserved and must be set to 0.

### `pAttr` [in]

This method supports the following Media Foundation attributes:

* [MF_MSE_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-mse-callback)
* [MF_MSE_BUFFERLIST_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-mse-bufferlist-callback)
* [MF_MSE_ACTIVELIST_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-mse-activelist-callback)

### `ppMSE` [out]

The [IMFMediaSourceExtension](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediasourceextension) which was created.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFMediaEngineClassFactoryEx](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineclassfactoryex)