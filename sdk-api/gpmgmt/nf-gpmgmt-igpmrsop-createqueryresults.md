# IGPMRSOP::CreateQueryResults

## Description

Executes a Resultant Set of Policy (RSoP) query. The method supports both logging mode and planning mode queries. Before calling this method, set the appropriate logging mode or planning mode properties. For more information and a list of properties, see
[IGPMRSOP Property Methods](https://learn.microsoft.com/previous-versions/windows/desktop/gpmc/igpmrsop-property-methods). RSoP planning mode requires a domain controller running Windows Server to perform the query.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

Call the
[IGPMRSOP::ReleaseQueryResults](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmrsop-releasequeryresults) method to release the WMI namespace created by this method.

In the GPMC UI, logging mode is also referred to as "Group Policy Results", and planning mode is also referred to as "Group Policy Modeling".

## See also

[IGPMRSOP](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmrsop)