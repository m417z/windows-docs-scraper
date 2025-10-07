# IGPMDomain::GetWMIFilter

## Description

Retrieves a
[GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object for the specified path.

## Parameters

### `bstrPath` [in]

Path of the [GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object to retrieve, in the following format: MSFT_SomFilter.Domain="*\<domain of the WMI filter>*", ID="*\<GUID that represents the WMI filter>*". Consider this example: MSFT_SomFilter.Domain="example.microsoft.com", ID="{7ab06d20-5e0a-4de9-8170-13dea779a528}".

### `ppWMIFilter` [out]

Address of a pointer to the
[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object.

### VB

Returns a reference to a [GPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter) object.

## See also

[IGPMDomain](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)