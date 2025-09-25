## Description

Gets the default color profile for a given display in the specified scope.

## Parameters

### `scope`

Specifies the association as system-wide or the current user.

### `targetAdapterID`

An identifier assigned to the adapter (e.g. GPU) of the target display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaydefault#remarks) for more details.

### `sourceID`

An identifier assigned to the source of the display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplaydefault#remarks) for more details.

### `profileType`

The type of color profile to return (currently only CPT_ICC is supported).

### `profileSubType`

The subtype of the color profile to return.

### `profileName`

Receives a pointer to the default color profile name, which must be freed with [LocalFree](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-localfree).

## Return value

## Remarks

See [connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays) for information on display adapter IDs and source IDs.

## See also

[Connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays)