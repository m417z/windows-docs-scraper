# CHANGER_SEND_VOLUME_TAG_INFORMATION structure

## Description

Contains information that the
[IOCTL_CHANGER_QUERY_VOLUME_TAGS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_query_volume_tags) control code uses to determine the volume information to be retrieved.

## Members

### `StartingElement`

A
[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element) structure that represents the starting element for which information is to be retrieved.

### `ActionCode`

The action to be performed.

| Value | Meaning |
| --- | --- |
| **ASSERT_ALTERNATE**<br><br>0x9 | Define the alternate volume tag of a volume that currently has none defined. <br><br>Requires that **Features0** is CHANGER_VOLUME_ASSERT. |
| **ASSERT_PRIMARY**<br><br>0x8 | Define the primary volume tag of a volume that currently has none defined. <br><br>Requires that **Features0** is CHANGER_VOLUME_ASSERT. |
| **REPLACE_ALTERNATE**<br><br>0xB | Replace the alternate volume tag with a new tag. <br><br>Requires that **Features0** is CHANGER_VOLUME_REPLACE. |
| **REPLACE_PRIMARY**<br><br>0xA | Replace the primary volume tag with a new tag. <br><br>Requires that **Features0** is CHANGER_VOLUME_REPLACE. |
| **SEARCH_ALL**<br><br>0x0 | Search all defined volume tags. <br><br>Requires that **Features0** is CHANGER_VOLUME_SEARCH. |
| **SEARCH_ALL_NO_SEQ**<br><br>0x4 | Search all defined volume tags, but ignore sequence numbers. <br><br>Requires that **Features0** is CHANGER_VOLUME_SEARCH. |
| **SEARCH_ALT_NO_SEQ**<br><br>0x6 | Search only alternate volume tags, but ignore sequence numbers. <br><br>Requires that **Features0** is CHANGER_VOLUME_SEARCH. |
| **SEARCH_ALTERNATE**<br><br>02 | Search only alternate volume tags. <br><br>Requires that **Features0** is CHANGER_VOLUME_SEARCH. |
| **SEARCH_PRI_NO_SEQ**<br><br>05 | Search only primary volume tags but ignore sequence numbers. <br><br>Requires that **Features0** is CHANGER_VOLUME_SEARCH. |
| **SEARCH_PRIMARY**<br><br>0x1 | Search only primary volume tags. <br><br>Requires that **Features0** is CHANGER_VOLUME_SEARCH. |
| **UNDEFINE_ALTERNATE**<br><br>0xD | Clear the alternate volume tag. <br><br>Requires that **Features0** is CHANGER_VOLUME_UNDEFINE. |
| **UNDEFINE_PRIMARY**<br><br>0xC | Clear the primary volume tag. <br><br>Requires that **Features0** is CHANGER_VOLUME_UNDEFINE. |

### `VolumeIDTemplate`

The template that the device uses to search for volume IDs. For search operations, the template can include wildcard characters to search for volumes that match the template. Supported wildcard characters include the asterisk (*) and question mark (?). For other operations, the template must specify a single volume.

## See also

[CHANGER_ELEMENT](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-changer_element)

[IOCTL_CHANGER_QUERY_VOLUME_TAGS](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_changer_query_volume_tags)