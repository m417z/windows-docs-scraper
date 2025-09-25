# IGPMWMIFilter::GetQueryList

## Description

Retrieves the query list stored in the WMI filter.

## Parameters

### `pQryList` [out]

Pointer to a **SAFEARRAY** of **VARIANT** members that contain the **BSTR**  strings representing the queries. Each **BSTR** string contains the query string along with the namespace information for that query.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

An array of strings representing the queries. Each string contains the query string along with the namespace information for that query.

### VB

An array of strings representing the queries. Each string contains the query string along with the namespace information for that query.

## See also

[IGPMWMIFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifilter)

[IGPMWMIFilterCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmwmifiltercollection)