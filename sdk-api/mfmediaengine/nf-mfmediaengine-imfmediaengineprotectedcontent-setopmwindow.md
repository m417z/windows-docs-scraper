# IMFMediaEngineProtectedContent::SetOPMWindow

## Description

Specifies the window that should receive output link protections.

## Parameters

### `hwnd` [in]

A handle to the window.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In frame-server mode, call this method to specify the destination window for protected video content. The Media Engine uses this window to set link protections, using the [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

## See also

[IMFMediaEngineProtectedContent](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineprotectedcontent)