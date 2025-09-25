# IWMWriterPreprocess::GetMaxPreprocessingPasses

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMaxPreprocessingPasses** method retrieves the maximum number of preprocessing passes for a specified input stream.

## Parameters

### `dwInputNum` [in]

**DWORD** containing the input number for which you want to get the maximum number of preprocessing passes.

### `dwFlags` [in]

Reserved. Set to zero.

### `pdwMaxNumPasses` [out]

Pointer to a **DWORD** that will receive the maximum number of preprocessing passes. If the codec supports two-pass encoding, this value is 1, as the final pass is not counted.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pdwMaxNumPasses* is **NULL**. |
| **E_INVALIDARG** | *dwInputNum* specifies an invalid input stream number. |
| **NS_E_INVALID_REQUEST** | The writer is not running. |

## Remarks

If no preprocessing is supported for the specified input, *pdwMaxNumPasses* contains zero upon return.

## See also

[IWMWriterPreprocess Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpreprocess)