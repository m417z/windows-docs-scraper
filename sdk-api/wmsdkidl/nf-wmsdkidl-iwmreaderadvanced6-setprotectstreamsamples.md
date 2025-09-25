# IWMReaderAdvanced6::SetProtectStreamSamples

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProtectStreamSamples** method configures sample protection.

## Parameters

### `pbCertificate` [in]

Buffer containing the certificate to use for protection.

### `cbCertificate` [in]

Size of the certificate in bytes.

### `dwCertificateType` [in]

Type of certificate passed in *pbCertificate*. The only supported type is WMDRM_CERTIFICATE_TYPE_XML.

### `dwFlags` [in]

The type of session protection to use for re-encoding. The only supported type is WMDRM_PROTECTION_TYPE_RC4.

### `pbInitializationVector` [out]

Receives the initialization vector. The initialization vector is OEAP-encrypted with the RSA public key found in the certificate. Set to **NULL** to receive the required buffer size in pcbInitializationVector.

### `pcbInitializationVector` [in, out]

On input, the size of the buffer passed as *pbInitializationVector*. On output, the size of the used portion of the buffer. If you pass **NULL** for *pbInitializationVector*, this value is set to the required buffer size on output.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **NS_E_DRM_RIV_TOO_SMALL** | An updated content revocation list is needed. |
| **S_OK** | The method succeeded. |

## Remarks

The constants used for *dwCertificateType* and *dwFlags* are defined in wmdrmsdk.h.

## See also

[IWMReaderAdvanced6 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced6)