# WMCreateReader function

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMCreateReader** function creates a reader object.

## Parameters

### `pUnkCert` [in]

This value must be set to **NULL**.

### `dwRights` [in]

**DWORD** indicating the desired operation. Set to one of the values from the [WMT_RIGHTS](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_rights) enumeration type, indicating the operation that is performed on this file. If multiple operations are being performed, *dwRights* must consist of multiple values from **WMT_RIGHTS** combined by using the bitwise **OR** operator.

### `ppReader` [out]

Pointer to a pointer to the [IWMReader](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader) interface of the newly created reader object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |
| **E_OUTOFMEMORY** | The function is unable to allocate memory for the new object. |

## Remarks

After this object has been created, you can modify the rights that will be requested for the next file opened by calling [IWMDRMReader::SetDRMProperty](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmdrmreader-setdrmproperty) with the [DRM_Rights](https://learn.microsoft.com/windows/desktop/wmformat/drm-rights) property. Note that when using this property, the rights are specified as strings, not as **DWORD** values.

The *dwRights* parameter may be set to 0 when reading non-DRM content. If *dwRights* is set to 0 and you open a protected file, you can access license related metadata, but you cannot read data from any streams in the file.

## See also

[DRM Attribute List](https://learn.microsoft.com/windows/desktop/wmformat/drm-attribute-list)

[DRM Properties](https://learn.microsoft.com/windows/desktop/wmformat/drm-properties)

[Enabling DRM Support](https://learn.microsoft.com/windows/desktop/wmformat/enabling-drm-support)

[Functions](https://learn.microsoft.com/windows/desktop/wmformat/functions)

[Reader Object](https://learn.microsoft.com/windows/desktop/wmformat/reader-object)