# IMFMediaEngine::GetCurrentSource

## Description

Gets the URL of the current media resource, or an empty string if no media resource is present.

## Parameters

### `ppUrl` [out]

Receives a **BSTR** that contains the URL of the current media resource. If there is no media resource, *ppUrl* receives an empty string. The caller must free the **BSTR** by calling **SysFreeString**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method corresponds to the **currentSrc** attribute of the **HTMLMediaElement** interface in HTML5.

Initially, the current media resource is empty. It is updated when the Media Engine performs the resource selection algorithm.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)