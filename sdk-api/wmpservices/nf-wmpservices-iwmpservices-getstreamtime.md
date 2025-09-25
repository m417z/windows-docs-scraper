# IWMPServices::GetStreamTime

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **IWMPServices::GetStreamTime** method retrieves a structure indicating the current stream time.

## Parameters

### `prt` [in]

Pointer to a **REFERENCE_TIME** structure.

## Return value

The method returns an **HRESULT**.

## Remarks

The current stream time is determined by Windows Media Player. This means that the value returned by this method do not necessarily represent the elapsed time relative to the beginning of the file. For instance, if the user moves the trackbar in the Player to seek the media to a new position, the value returned by this method returns the time elapsed since the media began playing from the new position. Changes in playback rate will also affect the value returned by this method.

The values provided in the **rtTimestamp** member of **IMediaObject::ProcessInput** and the **rtTimestamp** member of the **DMO_OUTPUT_DATA_BUFFER** structure supplied by **IMediaObject::ProcessOutput** contain values that indicate when the data provided in the buffer will be rendered relative to the current stream time. Therefore, these values also do not necessarily represent the elapsed time relative to the beginning of the file or the presentation time specified in the file.

## See also

[IWMPServices Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpservices)