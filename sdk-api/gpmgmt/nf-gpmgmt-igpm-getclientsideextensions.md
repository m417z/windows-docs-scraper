# IGPM::GetClientSideExtensions

## Description

Creates and returns a
[GPMCSECollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmcsecollection) object that allows you to enumerate Group Policy client-side extensions (CSEs) that are registered on the local computer.

## Parameters

### `ppIGPMCSECollection` [out]

Address of a pointer to the
[IGPMCSECollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmcsecollection) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMCSECollection** object.

### VB

Returns a reference to a **GPMCSECollection** object.

## See also

[IGPM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpm)

[IGPMCSECollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmcsecollection)