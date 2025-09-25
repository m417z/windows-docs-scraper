# IGPMResult::OverallStatus

## Description

Returns the overall status of a GPMC operation, such as a copy, restore, backup, or import. If no error occurred during the operation, the method returns a success code; otherwise the method returns a failure code.

**Note** You must check the code returned by this method as well as the one returned by the GPMC operation to determine whether or not the operation succeeded.

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## See also

[IGPMResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmresult)