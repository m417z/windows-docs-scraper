# IMFLocalMFTRegistration::RegisterMFTs

## Description

Registers one or more Media Foundation transforms (MFTs) in the caller's process.

## Parameters

### `pMFTs` [in]

A pointer to an array of [MFT_REGISTRATION_INFO](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mft_registration_info) structures.

### `cMFTs` [in]

The number of elements in the *pMFTs* array.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is similar to the [MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid) function. It registers one or more MFTs in the caller's process. These MFTs can be enumerated by calling the [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) function with the **MFT_ENUM_FLAG_LOCALMFT** flag.

Unlike [MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid), however, this method also makes the MFT available in the Protected Media Path (PMP) process, and is therefore useful if you are using the Media Session inside the PMP. For more information, see the following topics:

* [MFCreatePMPMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatepmpmediasession)
* [Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)

## See also

[IMFLocalMFTRegistration](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imflocalmftregistration)