# EventAccessRemove function (evntcons.h)

## Description

Removes the permissions defined in the registry for the specified provider or session.

## Parameters

### `Guid` [in]

GUID that uniquely identifies the provider or session whose permissions you want to remove from the
registry.

## Return value

Returns ERROR_SUCCESS if successful.

## Remarks

After removing the permission from the registry, the default permissions apply to the provider or session. For
details on the default permissions, see
[EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol).

## See also

[EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol)

[EventAccessQuery](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccessquery)