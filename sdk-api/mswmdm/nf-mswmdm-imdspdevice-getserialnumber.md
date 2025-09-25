# IMDSPDevice::GetSerialNumber

## Description

The **GetSerialNumber** method retrieves the serial number that uniquely identifies the device.

## Parameters

### `pSerialNumber` [out]

Pointer to a **WMDMID** structure that receives the serial number for the device. This parameter is included in the output message authentication code.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Not all media devices support serial numbers. To determine whether the device supports serial numbers, always check the return code when calling this method. If a media device does support serial numbers, the serial number of the media device is guaranteed to be unique.

This method is optional. When transferring protected content, Windows Media Device Manager uses [IMDSPStorageGlobals::GetSerialNumber](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-getserialnumber). For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)

[IMDSPStorageGlobals::GetSerialNumber](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-getserialnumber)