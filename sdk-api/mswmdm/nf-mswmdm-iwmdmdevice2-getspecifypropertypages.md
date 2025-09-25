# IWMDMDevice2::GetSpecifyPropertyPages

## Description

The **GetSpecifyPropertyPages** method retrieves the property page for the device. Property pages can be used to report device-specific properties and branding information.

## Parameters

### `ppSpecifyPropPages` [out]

Pointer to a pointer to an **ISpecifyPropertyPages** interface. **ISpecifyPropertyPages** is documented in the COM area of the Platform SDK. The caller must release this interface when done with it.

### `pppUnknowns` [out]

Specifies an array of **IUnknown** interface pointers. These interfaces are passed to the property page and can be used to pass information between the property page and the service provider. The array is allocated by Windows Media Device Manager, but the caller must call **Release** on each interface retrieved, and **CoTaskMemFree** on the retrieved array.

### `pcUnks` [out]

Retrieves the size of the *pppUnknowns* array.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice2)