## Description

Retrieves the list of profiles associated with a given display in the specified scope.

## Parameters

### `scope`

Specifies the association as system-wide or the current user.

### `targetAdapterID`

An identifier assigned to the adapter (e.g. GPU) of the target display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaylist#remarks) for more details.

### `sourceID`

An identifier assigned to the source of the display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaylist#remarks) for more details.

### `profileList`

Pointer to a buffer where the profile names are placed, must be freed with [LocalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree).

### `profileCount`

Receives the number of profiles names copied into profileList.

## Return value

**S_OK** for success, or a failure **HRESULT** value

## Remarks

See [connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays) for information on display adapter IDs and source IDs.

## See also

[Connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays)