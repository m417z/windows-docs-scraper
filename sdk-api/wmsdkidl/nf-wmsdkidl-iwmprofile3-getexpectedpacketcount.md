# IWMProfile3::GetExpectedPacketCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetExpectedPacketCount** method calculates the expected [packet](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) count for the specified duration. The packet count returned is only an estimate, and it is based upon the settings of the profile at the time this call is made.

## Parameters

### `msDuration` [in]

Specifies the duration in milliseconds.

### `pcPackets` [out]

Pointer to receive the count of packets expected for *msDuration* milliseconds.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pcPackets* is **NULL**. |
| **E_OUTOFMEMORY** | One of the internal objects required by the method could not be initialized. |
| **E_NOTIMPL** | The profile in the profile object is not compatible with this method. |

## Remarks

Problems will arise if the value passed in *msDuration* is not a positive number of milliseconds. The method will return S_OK as normal, but the packet count returned will not be correct.

It is impossible for this method to give exact counts, because there is no way to account for interleaved data in an encoded file. The packet count returned is most accurate for files with one audio stream. The more complicated the profile, the less accurate the packet count will be.

## See also

[IWMProfile3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)