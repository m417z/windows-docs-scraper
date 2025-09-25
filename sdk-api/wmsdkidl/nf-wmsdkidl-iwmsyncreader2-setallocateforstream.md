# IWMSyncReader2::SetAllocateForStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetAllocateForStream** method sets a sample allocation callback interface for allocating stream samples. This method enables you to use your own buffers for reading samples. Once set, the synchronous reader will call the [IWMReaderAllocatorEx::AllocateForStreamEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderallocatorex-allocateforstreamex) method every time it needs a buffer to hold a stream sample.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `pAllocator` [in]

Pointer to an [IWMReaderAllocatorEx](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderallocatorex) interface implemented in your application.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[Allocating Buffers for File Reading](https://learn.microsoft.com/windows/desktop/wmformat/allocating-buffers-for-file-reading)

[IWMSyncReader2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader2)

[IWMSyncReader2::GetAllocateForStream](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader2-getallocateforstream)