# IWMVideoMediaProps::GetMaxKeyFrameSpacing

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMaxKeyFrameSpacing** method retrieves the maximum interval between key frames.

## Parameters

### `pllTime` [out]

Pointer to a variable that receives the interval in 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pllTime* parameter is **NULL**. |

## Remarks

This method retrieves the value set by **SetMaxKeyFrameSpacing**, or the default value for the key frame spacing, during the encoding process only. If called for a file that is open in the reader, the method always returns zero.

For more information, see the Remarks for [SetMaxKeyFrameSpacing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmvideomediaprops-setmaxkeyframespacing).

## See also

[IWMVideoMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmvideomediaprops)