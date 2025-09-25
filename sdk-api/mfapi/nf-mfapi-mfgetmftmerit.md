# MFGetMFTMerit function

## Description

Gets the merit value of a hardware codec.

## Parameters

### `pMFT` [in, out]

A pointer to the **IUnknown** interface of the Media Foundation transform (MFT) that represents the codec.

### `cbVerifier` [in]

The size, in bytes, of the *verifier* array.

### `verifier` [in]

The address of a buffer that contains one of the following:

* The class identifier (CLSID) of the MFT.
* A null-terminated wide-character string that contains the symbol link for the underlying hardware device. Include the size of the terminating null in the value of *cbVerifier*.

### `merit` [out]

Receives the merit value.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The function fails if the MFT does not represent a hardware device with a valid Output Protection Manager (OPM) certificate.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[OPM_GET_CODEC_INFO](https://learn.microsoft.com/windows/desktop/medfound/opm-get-codec-info)