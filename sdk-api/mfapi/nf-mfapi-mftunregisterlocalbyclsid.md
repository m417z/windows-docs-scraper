# MFTUnregisterLocalByCLSID function

## Description

Unregisters a Media Foundation transform (MFT) from the caller's process.

## Parameters

### `clsidMFT` [in]

The class identifier (CLSID) of the MFT.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| **HRESULT_FROM_WIN32(**ERROR_NOT_FOUND**)** | The MFT specified by the *clsidMFT* parameter was not registered in this process. |

## Remarks

Use this function to unregister a local MFT that was previously registered through the [MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid) function.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)