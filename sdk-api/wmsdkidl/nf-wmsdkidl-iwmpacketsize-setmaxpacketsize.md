# IWMPacketSize::SetMaxPacketSize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetMaxPacketSize** method specifies the maximum size of a [packet](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in an ASF file.

## Parameters

### `dwMaxPacketSize` [in]

**DWORD** containing the maximum packet size, in bytes. Set this to zero if the writer is to generate packets of various sizes. Otherwise, it must be a value between 100 bytes and 64 kilobytes.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *dwMaxPacketSize* parameter contains an invalid value for the maximum packet size. |

## Remarks

By default, the maximum packet size is 1400 bytes (chosen because it is below the 1500-byte Ethernet maximum transition unit (MTU) plus the generic routing encapsulation (GRE) tunneling header size). The writer attempts to send 10 packets per second up to but not exceeding the value of the defined maximum packet size.

This method is designed for use with only single bit rate video; it should not be applied to a multiple bit rate stream. Note also that the maximum value applies only to the data; a small amount will be added for the header. For this reason there will be a small variance between the setting specified by this method and the actual maximum packet size reported by other tools for the stream.

## See also

[IWMPacketSize Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpacketsize)

[IWMPacketSize2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpacketsize2)

[IWMPacketSize::GetMaxPacketSize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmpacketsize-getmaxpacketsize)