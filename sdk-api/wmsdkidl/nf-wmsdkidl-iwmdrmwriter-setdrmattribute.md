# IWMDRMWriter::SetDRMAttribute

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**SetDRMAttribute** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **SetDRMAttribute** method sets DRM-header attributes as well as other DRM run-time properties.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number to which the attribute applies.

### `pszName` [in]

Pointer to a null-terminated string containing the attribute name. See Remarks for supported attributes.

### `Type` [in]

A value from the [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration type specifying the data type of the attribute data.

### `pValue` [in]

Pointer to an array of bytes containing the attribute data.

### `cbLength` [in]

The size, in bytes, of the attribute data pointed to by *pValue*.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method is somewhat misnamed because it is used to set not only writable DRM file attributes (See [DRM Attribute List](https://learn.microsoft.com/windows/desktop/wmformat/drm-attribute-list)), but also certain DRM properties that are used by the DRM run-time components but are not written to the DRM header in the file. (See [DRM Properties](https://learn.microsoft.com/windows/desktop/wmformat/drm-properties).)

The properties **Use_Advanced_DRM** and **Use_DRM** may be specified before a profile is set. No other properties can be set before a profile is set. The following code snippet shows how to call this function, using the [DRM_ContentID](https://learn.microsoft.com/windows/desktop/wmformat/drm-contentid) property as an example. Assume that *pDRMWriter* is a **IWMDRMWriter** interface pointer, and *wszContentID* is an array of type **WCHAR**.

```cpp

hr = pDRMWriter->SetDRMAttribute( 0, g_wszWMDRM_ContentID,
        WMT_TYPE_STRING, (BYTE *)wszContentID,
        ( wcslen( wszContentID ) + 1 ) * sizeof( WCHAR ) );

```

## See also

[DRM Attribute List](https://learn.microsoft.com/windows/desktop/wmformat/drm-attribute-list)

[DRM Properties](https://learn.microsoft.com/windows/desktop/wmformat/drm-properties)

[IWMDRMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmwriter)