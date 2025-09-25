# IWMPVideoRenderConfig::put_presenterActivate

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **put_presenterActivate** method provides Windows Media Player with an activation object for a custom video presenter.

## Parameters

### `pActivate` [in]

A pointer to an **IMFActivate** interface that Windows Media Player or another Windows component will use to activate the custom video presenter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

In certain situations, Windows Media Player uses a video pipeline that includes the enhanced video renderer (EVR). The EVR is a system component that allows other components and applications to provide custom plug-ins that perform tasks like video mixing and video presenting.

An application that embeds Windows Media Player can provide a custom video presenter for the EVR by calling **put_presenterActivate**. The application must create its own activation object that implements the **IMFActivate** interface. The application provides Windows Media Player with that interface in the *pActivate* parameter. When Windows Media Player or another system component needs to create an instance of the custom presenter, it calls the **ActivateObject** method of the **IMFActivate** interface provided by the application.

The activation object is responsible for initializing the custom presenter. The nature of the initialization and the format of any context data required for the initialization are completely under the control of those who develop the custom presenter and the activation object.

The EVR, custom presenters, activation objects, and the **IMFActivate** interface are documented in the Microsoft Media Foundation SDK, which is part of the Microsoft Windows SDK.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPVideoRenderConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmprealestate/nn-wmprealestate-iwmpvideorenderconfig)