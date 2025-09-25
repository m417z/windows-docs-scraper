# IWMDMDevice::GetStatus

## Description

The **GetStatus** method retrieves device status information.

## Parameters

### `pdwStatus` [out]

Pointer to a **DWORD** specifying the device status. The possible values returned in *pdwStatus* are provided in the following table.

| Status | Description |
| --- | --- |
| WMDM_STATUS_READY | Windows Media Device Manager and its subcomponents are in a ready state. |
| WMDM_STATUS_BUSY | An operation is ongoing. Evaluate status values to determine the operation. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice)