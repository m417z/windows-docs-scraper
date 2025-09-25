## Description

Gets the currently selected color profile scope of the provided display - either user or system.

## Parameters

### `targetAdapterID`

An identifier assigned to the adapter (e.g. GPU) of the target display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplayuserscope#remarks) for more details.

### `sourceID`

An identifier assigned to the source of the display. See [Remarks](https://learn.microsoft.com/windows/win32/api/icm/nf-icm-colorprofilegetdisplayuserscope#remarks) for more details.

### `scope`

Returns the scope of the currently selected color profile - either the current user or system.

## Return value

**S_OK** for success, or a failure **HRESULT** value

## Remarks

See [connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays) for information on display adapter IDs and source IDs.

## See also

[Connecting and configuring displays](https://learn.microsoft.com/windows-hardware/drivers/display/connecting-and-configuring-displays)