# IWMPTranscodePolicy::allowTranscode

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **allowTranscode** method retrieves a value specifying whether Windows Media Player is permitted to change the format of the digital media content to the Windows Media format.

## Parameters

### `pvbAllow` [out]

Pointer to a **VARIANT_BOOL** that contains a value indicating whether transcoding is permitted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Value | Description |
| --- | --- |
| S_OK | The method succeeded. |

## Remarks

When you copy to a device a digital media file that is in a custom format, you must change the format of the content if the device does not support the custom format. This process is called transcoding.

If the format used by a digital media file is not supported, Windows Media Player first checks the registry for existing permission to transcode, as described in [File Name Extension Registry Settings](https://learn.microsoft.com/windows/desktop/WMP/file-name-extension-registry-settings). If the custom format type is registered for permission to transcode, Windows Media Player locates the DirectShow source filter for the custom format type and calls **QueryInterface** to retrieve a pointer to **IWMPTranscodePolicy**. If the interface pointer is retrieved, the Player calls **IWMPTranscodePolicy::allowTranscode**. If **allowTranscode** returns VARIANT_TRUE, Windows Media Player performs the necessary transcoding. Otherwise, Windows Media Player does not copy the digital media file to the device. If any filter in the DirectShow graph returns VARIANT_FALSE from **allowTranscode**, the transcoding operation will fail.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPTranscodePolicy Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmptranscodepolicy)