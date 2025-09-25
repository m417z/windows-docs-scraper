## Description

Links the specified GPO to the specified position in the list of GPOs that are linked to a particular SOM. If another GPO link occupies the specified position, the method inserts the new link ahead of the older link, and moves the older link, and all subsequent links in the list, down by one.

## Parameters

### `lLinkPos` [in]

Position in which the GPO should be linked. The position is 1-based. If this parameter is – 1, the GPO is appended to the end of the list. If the position specified is greater than the current number of GPO links, the method fails and returns **E_INVALIDARG**.

### `pGPO` [in]

GPO to link.

### `ppNewGPOLink` [out]

Address of a pointer to the
[IGPMGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolink) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a **GPMGPOLink** object.

### VB

Returns a reference to a **GPMGPOLink** object.

## Remarks

Attempting to link a GPO to a particular SOM multiple times causes the method to fail with **ERROR_ALREADY_EXISTS**.

## See also

[IGPMGPO](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpo)

[IGPMGPOLink](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmgpolink)

[IGPMSOM](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmsom)