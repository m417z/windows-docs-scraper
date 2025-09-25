# IMDSPDevice::GetFormatSupport

## Description

The **GetFormatSupport** method retrieves all the formats supported by the device. The format information includes codecs, file formats, and digital rights management schemes.

## Parameters

### `pFormatEx` [out]

Pointer to an array of [_WAVEFORMATEX](https://learn.microsoft.com/windows/desktop/WMDM/-waveformatex) structures containing information about codecs and bit rates supported by the device.

### `pnFormatCount` [out]

Pointer to the number of elements in the *pFormatEx* array.

### `pppwszMimeType` [out]

Pointer to an array that describes file formats and digital rights management schemes supported by the device.

### `pnMimeTypeCount` [out]

Pointer to the number of elements in the *pppwszMimeType* array.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Memory for the *pFormatEx* and *pppwszMimeType* parameters is allocated by this method and must be freed by the caller using **CoTaskMemFree**, a standard Win32 function.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)