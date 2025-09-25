# IMDSPStorageGlobals::GetSerialNumber

## Description

The **GetSerialNumber** method retrieves a serial number uniquely identifying the storage medium. This method must be implemented for protected content transfer, but otherwise it is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

.

## Parameters

### `pSerialNum` [out]

Pointer to a **WMDMID** structure containing the serial number information. This parameter is included in the output message authentication code.

### `abMac` [in, out]

Array of eight bytes containing the message authentication code for the parameter data of this method. (WMDM_MAC_LENGTH is defined as 8.)

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Not all storage media support serial numbers. The return code must always be checked to determine whether the storage medium provides this support. If the storage medium does not support returning a unique serial number, protected content cannot be transferred to the medium. If the storage represented is removable media, the serial number returned must be the storage serial number, which should be distinct from the device serial number.

## See also

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)

[WMDMID](https://learn.microsoft.com/windows/desktop/WMDM/wmdmid)