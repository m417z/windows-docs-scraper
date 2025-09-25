# IMDSPDevice2::GetSpecifyPropertyPages

## Description

The **GetSpecifyPropertyPages** method gets property pages describing non-standard capabilities of portable devices.

## Parameters

### `ppSpecifyPropPages` [out]

Pointer to a Win32 **ISpecifyPropertyPages** interface pointer.

### `pppUnknowns` [out]

Array of **IUnknown** interface pointers. These interfaces will be passed to the property page and can be used to pass information between the property page and the service provider.

### `pcUnks` [out]

Size of the *pppUnknowns* array.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Memory for the *pppUnknowns* array should be allocated by this method and must be freed by the caller using **CoTaskMemFree**, a standard Win32 function.

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice2)