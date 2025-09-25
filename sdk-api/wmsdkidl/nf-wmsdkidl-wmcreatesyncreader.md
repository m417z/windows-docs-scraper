# WMCreateSyncReader function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCreateSyncReader** function creates a synchronous reader object.

## Parameters

### `pUnkCert` [in]

Pointer to an **IUnknown** interface. This value must be set to **NULL**.

### `dwRights` [in]

**DWORD** specifying the desired operation. When playing back non-DRM content, or for an application that does not have DRM rights, this value can be set to zero. Otherwise, this value must be one of the values from the [WMT_RIGHTS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_rights) enumeration type, indicating the operation that is performed on this file. If multiple operations are being performed, **dwRights** must consist of multiple values from **WMT_RIGHTS** combined by using the bitwise **OR** operator.

### `ppSyncReader` [out]

Pointer to a pointer to the [IWMSyncReader](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader) interface of the newly created synchronous reader object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_OUTOFMEMORY** | The function is unable to allocate memory for the new object. |

## See also

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)

[Synchronous Reader Object](https://learn.microsoft.com/windows/desktop/wmformat/synchronous-reader-object)