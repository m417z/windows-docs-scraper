# IWMDRMWriter3::SetProtectStreamSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**SetProtectStreamSamples** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **SetProtectStreamSamples** method configures the writer to accept encrypted stream samples. This method is used as part of the process of importing protected content from a third party content protection scheme (CPS) into Windows Media DRM.

## Parameters

### `pImportInitStruct` [in]

Address of a [WMDRM_IMPORT_INIT_STRUCT](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wmdrm_import_init_struct) structure containing initialization information needed to import protected content.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **NS_E_DRM_RIV_TOO_SMALL** | An updated content revocation list is needed. |
| **S_OK** | The method succeeded. |

## Remarks

**SetProtectStreamSamples** is used to configure the writer object for importing protected content.

When importing protected content, this method must be called after configuring the writer but before calling [IWMWriter::BeginWriting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-beginwriting). Before you can call this method, you must validate and extract the machine Windows Media DRM public key from the machine certificate collection.

## See also

[DRM Import](https://learn.microsoft.com/windows/desktop/wmformat/drm-import)

[IWMDRMSecurity::GetMachineCertificate](https://learn.microsoft.com/windows/desktop/wmformat/iwmdrmsecurity-getmachinecertificate)

[IWMDRMSecurity::PerformSecurityUpdate](https://learn.microsoft.com/windows/desktop/wmformat/iwmdrmsecurity-performsecurityupdate)

[IWMDRMWriter3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmwriter3)