# IMFMediaEngine::GetError

## Description

Gets the most recent error status.

## Parameters

### `ppError` [out]

Receives either a pointer to the [IMFMediaError](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaerror) interface, or the value **NULL**. If the value is **non-NULL**, the caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method returns the last error status, if any, that resulted from loading the media source. If there has not been an error, *ppError* receives the value **NULL**.

This method corresponds to the **error** attribute of the **HTMLMediaElement** interface in HTML5.

## See also

[IMFMediaEngine](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengine)