## Description

Mount manager clients that are able to keep track of their drive letters use this structure to request that the mount manager assign them a particular link name.

## Members

### `UseOnlyIfThereAreNoOtherLinks`

Indicates that the mount manager should use the suggested link name only if there are no other persistent links assigned to the client.

### `NameLength`

Contains the length of the suggested name, in bytes.

### `Name`

Contains a variable-sized array of wide characters that holds the name of the suggested link in wide characters. Drive letter names must include the full path of the symbolic link in object namespace and must have the traditional Microsoft MS-DOS syntax. For instance, drive letter "D" must be represented in this manner: "\DosDevices\D:". The alternative symbolic link path of "\??\D:" can't be used, nor can abbreviations of the symbolic link such as "D:".

## Remarks

As a best practice, the implementer must not thread synchronize and must not make blocking and/or Interprocess Communication (IPC) function calls.

For more information, see [Supporting Mount Manager Requests in a Storage Class Driver](https://learn.microsoft.com/windows-hardware/drivers/storage/supporting-mount-manager-requests-in-a-storage-class-driver).

## See also

[IOCTL_MOUNTDEV_QUERY_SUGGESTED_LINK_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/mountdev/ni-mountdev-ioctl_mountdev_query_suggested_link_name)