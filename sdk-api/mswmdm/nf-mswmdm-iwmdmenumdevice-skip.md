# IWMDMEnumDevice::Skip

## Description

The **Skip** method skips over a specified number of devices in the enumeration sequence.

## Parameters

### `celt` [in]

Number of devices to skip.

### `pceltFetched` [out]

Number of devices actually skipped.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the requested number of devices to skip is greater than the remaining devices, the return value from **Skip** is S_FALSE. At this point, *pceltFetched* must be used to determine the number of interfaces skipped. If you skip to the end of the device array, a subsequent call to *Next* also returns S_FALSE. For more information about the standard enumerator Skip method, see the Microsoft COM documentation, available at the Microsoft Web site.

## See also

[IWMDMEnumDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumdevice)