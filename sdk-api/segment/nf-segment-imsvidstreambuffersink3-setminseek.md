# IMSVidStreamBufferSink3::SetMinSeek

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **SetMinSeek** method sets the minimum seek position equal to the current playback position, and retrieves the current position.

## Parameters

### `pdwMin` [out]

Receives the current position, in hundredths of seconds.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSink3 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidstreambuffersink3)