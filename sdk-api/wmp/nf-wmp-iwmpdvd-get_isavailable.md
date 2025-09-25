# IWMPDVD::get_isAvailable

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **get_isAvailable** method indicates whether a specified type of information is available or a specified action can be performed.

## Parameters

### `bstrItem` [in]

**BSTR** containing one of the following values.

| Value | Description |
| --- | --- |
| back | Determines whether the **IWMPDVD::back** method is available. |
| dvd | Determines whether the DVD is loaded. |
| dvdDecoder | Determines whether the DVD decoder is installed on system. |
| resume | Determines whether the **IWMPDVD::resume** method is available. |
| titleMenu | Determines whether the **IWMPDVD::titleMenu** method is available. |
| topMenu | Determines whether the **IWMPDVD::topMenu** method is available. Commonly called the root menu. |

### `pIsAvailable` [out]

Pointer to a **VARIANT_BOOL** that indicates whether the specified parameter is available.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The DVD features of Windows Media Player will not work on computers that do not have a DVD decoder installed. You can determine whether a decoder is available by calling the **get_isAvailable** method and passing in the **BSTR** value "dvdDecoder".

Every DVD is authored differently. The methods available during DVD playback and navigation depend on how the DVD is authored.

**Windows Media Player 10 Mobile:** This method always retrieves a **VARIANT_BOOL** set to **FALSE**.

## See also

[IWMPDVD Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpdvd)

[IWMPDVD::back](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpdvd-back)

[IWMPDVD::resume](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpdvd-resume)

[IWMPDVD::titleMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpdvd-titlemenu)

[IWMPDVD::topMenu](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpdvd-topmenu)