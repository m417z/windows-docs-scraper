# IMFTrustedOutput::GetOutputTrustAuthorityByIndex

## Description

Gets an output trust authority (OTA), specified by index.

## Parameters

### `dwIndex` [in]

Zero-based index of the OTA to retrieve. To get the number of OTAs provided by this object, call [IMFTrustedOutput::GetOutputTrustAuthorityCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftrustedoutput-getoutputtrustauthoritycount).

### `ppauthority` [out]

Receives a pointer to the [IMFOutputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputtrustauthority) interface of the OTA. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTrustedOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedoutput)