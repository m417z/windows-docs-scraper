# IWMPControls3::get_currentPositionTimecode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_currentPositionTimecode** method retrieves the current position in the current media item using a time code format. This method currently supports SMPTE time code.

## Parameters

### `bstrTimecode` [out]

Pointer to a **BSTR** containing the time code.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

SMPTE time code provides a standard way of identifying an individual video frame, which is useful for synchronizing playback. If a digital media file supports SMPTE time code, Windows Media Player can retrieve the current time code position information or seek to a video frame identified by a **BSTR** containing a particular time code.

SMPTE time code identifies a particular frame by the number of hours, minutes, seconds, and frames that separate it from a particular reference frame—the frame designated as time zero. Usually the time zero frame is the start of the file and a particular SMPTE time code value represents the elapsed time since the start of the file.

The time code is in the format [*range*]*hh*:*mm*:*ss*.*ff* where [*range*] represents the range, *hh* represents hours, *mm* represents minutes, *ss* represents seconds, and *ff* represents frames. When specifying a value for **IWMPControls3::put_currentPositionTimecode**, you must include all eight digits, using zeros as placeholders.

[*range*] corresponds to the **wRange** member of the Windows Media Format **WMT_TIMECODE_EXTENSION_DATA** structure. For more information about time code ranges, see the Windows Media Format SDK.

Specifying and retrieving values by using **put_currentPositionTimecode** and **get_currentPositionTimecode** are supported only for files that contain SMPTE time code information.

**Windows Media Player 10 Mobile:** When retrieving or specifying an SMPTE time code through the object model, the range and frames sections of the time code format are not supported.

## See also

[IWMPControls3 Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpcontrols3)

[IWMPControls3::put_currentPositionTimecode](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpcontrols3-put_currentpositiontimecode)