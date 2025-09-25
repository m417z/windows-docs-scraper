# MFCreateVideoRendererActivate function

## Description

Creates an activation object for the enhanced video renderer (EVR) media sink.

## Parameters

### `hwndVideo` [in]

Handle to the window where the video will be displayed.

### `ppActivate` [out]

Receives a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. Use this interface to create the EVR. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

To create the EVR, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) on the retrieved [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer. (If you are using the Media Session, the Media Session automatically calls **ActivateObject** when you queue the topology.)

To configure the EVR, set any of the following attributes on the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) object before calling [ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject).

| Attribute | Description |
| --- | --- |
| [MF_ACTIVATE_CUSTOM_VIDEO_MIXER_ACTIVATE](https://learn.microsoft.com/windows/desktop/medfound/mf-activate-custom-video-mixer-activate-attribute) | Activation object for a custom mixer. |
| [MF_ACTIVATE_CUSTOM_VIDEO_MIXER_CLSID](https://learn.microsoft.com/windows/desktop/medfound/mf-activate-custom-video-mixer-clsid-attribute) | CLSID for a custom mixer. |
| [MF_ACTIVATE_CUSTOM_VIDEO_MIXER_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-activate-custom-video-mixer-flags-attribute) | Flags for creating a custom mixer. |
| [MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_ACTIVATE](https://learn.microsoft.com/windows/desktop/medfound/mf-activate-custom-video-presenter-activate-attribute) | Activation object for a custom presenter. |
| [MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_CLSID](https://learn.microsoft.com/windows/desktop/medfound/mf-activate-custom-video-presenter-clsid-attribute) | CLSID for a custom presenter. |
| [MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_FLAGS](https://learn.microsoft.com/windows/desktop/medfound/mf-activate-custom-video-presenter-flags-attribute) | Flags for creating a custom presenter. |

When [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) is called, the activation objects sets the video window on the EVR by calling [IMFVideoDisplayControl::SetVideoPosition](https://learn.microsoft.com/windows/desktop/api/evr/nf-evr-imfvideodisplaycontrol-setvideoposition). Passing **NULL** for the *hwndVideo* parameter is not an error, but no video will render unless the EVR has a valid video window.

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/medfound/enhanced-video-renderer)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)