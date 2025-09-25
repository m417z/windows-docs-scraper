# IWMPContentPartner::StationEvent

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **StationEvent** method notifies the plug-in of events during playback of a Windows Media metafile playlist (ASX file).

## Parameters

### `bstrStationEventType` [in]

**BSTR** containing the event type. The caller (Windows Media Player) sets this parameter to one of the following values.

| String | Description |
| --- | --- |
| g_szStationEvent_Started | A track started playing. |
| g_szStationEvent_Complete | A track finished playing. |
| g_szStationEvent_Skipped | A track was skipped. |

### `StationId` [in]

The station ID.

### `PlaylistIndex` [in]

The playlist index.

### `TrackID` [in]

The track ID.

### `TrackData` [in]

**BSTR** containing track data.

### `dwSecondsPlayed` [in]

Number of seconds that the playlist was played.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is called to enable logging of certain ASX events when an ASX file created by the online store is played.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)

[Windows Media Metafiles Overview](https://learn.microsoft.com/windows/desktop/WMP/windows-media-metafiles-overview)