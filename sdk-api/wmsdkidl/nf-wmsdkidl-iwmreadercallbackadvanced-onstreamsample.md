# IWMReaderCallbackAdvanced::OnStreamSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnStreamSample** method delivers stream samples from the source file without decompressing them first.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `cnsSampleTime` [in]

**QWORD** containing the sample time, in 100-nanosecond units.

### `cnsSampleDuration` [in]

**QWORD** containing the sample duration, in 100-nanosecond units.

### `dwFlags` [in]

The flags that can be specified have the following uses.

| Flag | Description |
| --- | --- |
| No flag set | None of the conditions for the other flags applies. For example, a [delta frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in most cases would not have any flags set for it. |
| WM_SF_CLEANPOINT | This is the same as a [key frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary). It indicates a good point to go to during a seek, for example. |
| WM_SF_DISCONTINUITY | The data stream has a gap in it, which could be due to a seek, a network loss, or other reason. This can be useful extra information for an application such as a codec or renderer. The flag is set on the first piece of data following the gap. |
| WM_SF_DATALOSS | Some data has been lost between the previous sample, and the sample with this flag set. |

### `pSample` [in]

Pointer to a sample stored in an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface. The reader calls **SAFE_RELEASE** on this pointer after your **OnStreamSample** method returns. You can call **AddRef** on this pointer if you need to keep a reference count on the buffer. Do not call **Release** on this pointer unless you have called **AddRef**.

### `pvContext` [in]

Generic pointer, for use by the application.

## Return value

To use this method, you must implement it in your application. You can return whatever **HRESULT** error codes are appropriate to your implementation. For more information about the **HRESULT** error codes included for use by the Windows Media Format SDK, see [Error Codes](https://learn.microsoft.com/windows/desktop/wmformat/error-codes).

## Remarks

When using the asynchronous reader, only compressed samples can be delivered for a stream number. If you want to retrieve uncompressed samples by stream number, you should use the synchronous reader.

There are many reasons why you might want to retrieve compressed samples. The most common use is to transfer a stream from one ASF file to another.

If you receive compressed samples, you must either keep them compressed, or decompress them with your application. The Windows Media Format SDK does not provide methods to decompress samples once they have been removed from a file.

This method is not able to deliver secure content. If protected content is used, the method will return NS_E_PROTECTEDCONTENT.

The samples delivered by this method are compressed, but are in all other ways exactly the same as samples delivered through [IWMReaderCallback::OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample).

To get samples for a particular stream, call [IWMReaderAdvanced::SetReceiveStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced-setreceivestreamsamples).

## See also

[IWMReaderCallbackAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallbackadvanced)