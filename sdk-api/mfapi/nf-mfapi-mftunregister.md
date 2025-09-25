# MFTUnregister function

## Description

Unregisters a Media Foundation transform (MFT).

## Parameters

### `clsidMFT` [in]

The CLSID of the MFT.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function removes the registry entries created by the [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister) function.

It is safe to call **MFTUnregister** twice with the same CLSID. If the CLSID is not found in the registry, the function succeeds and does nothing.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)