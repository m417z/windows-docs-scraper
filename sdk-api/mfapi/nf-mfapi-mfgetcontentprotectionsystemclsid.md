# MFGetContentProtectionSystemCLSID function

## Description

Gets the class identifier for a content protection system.

## Parameters

### `guidProtectionSystemID` [in]

The GUID that identifies the content protection system.

### `pclsid` [out]

Receives the class identifier to the content protection system.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The class identifier can be used to create the input trust authority (ITA) for the content protection system. Call [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) or [IMFPMPHost::CreateObjectByCLSID](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfpmphost-createobjectbyclsid) to get an [IMFTrustedInput](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftrustedinput) pointer.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)