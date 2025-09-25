## Description

Associates an installed color profile with a specified display in the given scope.

## Parameters

### `scope`

Specifies the association as system-wide or the current user.

### `profileName`

Identifies the installed profile to associate.

### `targetAdapterID`

An identifier assigned to the adapter (e.g. GPU) of the target display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofileadddisplayassociation#remarks) for more details.

### `sourceID`

An identifier assigned to the source of the display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofileadddisplayassociation#remarks) for more details.

### `setAsDefault`

Whether or not to set the newly associated profile as the default.

### `associateAsAdvancedColor`

Specifies to which association list the new profile is added.

## Return value

**S_OK** for success, or a failure **HRESULT** value

## Remarks

See [connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays) for information on display adapter IDs and source IDs.

## See also

[Connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays)