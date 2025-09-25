# FILESHARE_CHANGE structure

## Description

Describes the format for an entry in an event notification list.

## Members

### `Change`

Describes a change event. This value is taken from the
[FILESHARE_CHANGE_ENUM](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-fileshare_change_enum) enumeration. The following
are the possible values for this member.

#### FILESHARE_CHANGE_ADD (1)

A new file share resource has been created and will be included with the other file shares managed by the
File Server resource.

#### FILESHARE_CHANGE_DEL (2)

A file share resource has been deleted and will be removed from the file shares managed by the File Server
resource.

#### FILESHARE_CHANGE_MODIFY (3)

One or more properties of an existing file share resource have been changed.

### `ShareName`

The name of the file share resource specific to this entry in the event notification list.

## See also

[FILESHARE_CHANGE_ENUM](https://learn.microsoft.com/windows/desktop/api/clusapi/ne-clusapi-fileshare_change_enum)

[Utility Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/utility-structures)