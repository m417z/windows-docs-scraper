# IWMPConvert::GetErrorURL

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetErrorURL** method is implemented by a conversion plug-in and called by Windows Media Player to retrieve the URL of a webpage that displays information to help the user correct the condition that caused an error.

## Parameters

### `pbstrURL` [out]

Pointer to a **BSTR** that receives the URL of the webpage that displays the error information.

## Return value

The method returns an **HRESULT**.

## Remarks

This is a synchronous call. Your code must complete and return as quickly as possible.

**Windows Media Player 10 Mobile:** This method is not supported.

## See also

[IWMPConvert Interface](https://learn.microsoft.com/windows/desktop/api/wmpservices/nn-wmpservices-iwmpconvert)