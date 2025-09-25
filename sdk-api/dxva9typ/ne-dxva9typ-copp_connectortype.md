## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the type of physical connector.

## Constants

### `COPP_ConnectorType_Unknown:-1`

Unknown connector type.

### `COPP_ConnectorType_VGA:0`

VGA (Video Graphics Array) connector.

### `COPP_ConnectorType_SVideo:1`

S-Video connector.

### `COPP_ConnectorType_CompositeVideo:2`

Composite video connector.

### `COPP_ConnectorType_ComponentVideo:3`

Component video connector.

### `COPP_ConnectorType_DVI:4`

DVI (digital video interface) connector.

### `COPP_ConnectorType_HDMI:5`

HDMI (high-definition multimedia interface) connector.

### `COPP_ConnectorType_LVDS:6`

LVDS (Low voltage differential signaling) connector.

### `COPP_ConnectorType_TMDS:7`

Reserved.

### `COPP_ConnectorType_D_JPN:8`

Japanese D connector. (Connector conforming to the EIAJ RC-5237 standard.)

### `COPP_ConnectorType_Internal:0x80000000`

Internal connector. This flag can be combined with the other flags. This flag indicates that the connection between the graphics adapter and the display device is permanent and not accessible to the user.

### `COPP_ConnectorType_ForceDWORD`

Reserved. Do not use.

## Remarks

If a connector is described as *embedded* or *integrated*, it implies that the connector is internal. These connectors have "Embedded" in the name of the enumeration constant.

Applications should ignore the **COPP_ConnectorType_Internal** flag and instead check for connector types with "Embedded" in the constant name.

## See also

[DirectShow Enumerated Types](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-enumerated-types)

[Using Certified Output Protection Protocol (COPP)](https://learn.microsoft.com/windows/desktop/DirectShow/using-certified-output-protection-protocol--copp)