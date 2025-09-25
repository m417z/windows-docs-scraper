# IGPMGPO::Delete

## Description

Deletes a Group Policy object (GPO) from the directory service and from the system volume folder (SYSVOL).

## Return value

### JScript

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### VB

Returns **S_OK** if successful. Returns a failure code if an error occurs.

## Remarks

This method does not delete GPO links. To delete GPO links, call the
[IGPMGPOLink::Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nf-gpmgmt-igpmgpolink-delete) method.

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)