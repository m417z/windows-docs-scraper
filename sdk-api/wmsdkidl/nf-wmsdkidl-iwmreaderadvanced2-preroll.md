# IWMReaderAdvanced2::Preroll

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Preroll** method is used to begin prerolling (buffering data) for the reader.

## Parameters

### `cnsStart` [in]

Specifies the start time in 100-nanosecond units.

### `cnsDuration` [in]

Specifies the duration in 100-nanosecond units.

### `fRate` [in]

Specifies the data rate.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method can be called before the application calls [Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) to begin buffering data in advance. The parameters here must be set to the same values as those that are passed to **Start** when it is called. If the parameters are different, **Start** will do rebuffering.

It is important to allow sufficient time for the prerolling (buffering data) for the reader to be completed before calling **Start**. When prerolling local files, 6 seconds normally is sufficient. When prerolling files over the Internet, allow more time before calling **Start**. If insufficient time is allowed, the effect will be a longer **Start** time when **Start** is called.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)