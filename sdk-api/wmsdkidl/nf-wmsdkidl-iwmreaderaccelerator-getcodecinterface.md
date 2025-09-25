# IWMReaderAccelerator::GetCodecInterface

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecInterface** method is used to retrieve a pointer to the [IWMCodecAMVideoAccelerator](https://learn.microsoft.com/windows/desktop/api/wmdxva/nn-wmdxva-iwmcodecamvideoaccelerator) interface exposed on the decoder [DMO](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary).

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `riid` [in]

Reference to the IID of the interface to obtain. The value must be IID_IWMCodecAMVideoAccelerator.

### `ppvCodecInterface` [out]

Address of a pointer that receives the interface specified by *riid*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_UNEXPECTED** | The WM Reader has no pointer to the codec. |

## See also

[Enabling DirectX Video Acceleration](https://learn.microsoft.com/windows/desktop/wmformat/enabling-directx-video-acceleration)

[IWMReaderAccelerator Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderaccelerator)