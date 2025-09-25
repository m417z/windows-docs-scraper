# _SET_UNIT_DIRECTORY structure

## Description

This structure is used to assign settings for a unit directory. The request exposes a unit directory within the configuration ROM of the local host. This request is used to create or remove a Configuration ROM entry in the configuration ROM of a local node. A driver is responsible for removing the Configuration ROM entries it has created before the system unloads the driver.

## Members

### `Flags`

On input, specifies whether to add or remove a unit directory. Can be ADD_UNIT_DIRECTORY_ENTRY to add a unit directory, or REMOVE_UNIT_DIRECTORY_ENTRY to remove a unit directory. If ISSUE_BUS_RESET_AFTER_MODIFY is also set, a bus reset will be issued after the add or remove.

### `UnitSpecId`

On input, the UnitSpecId value to use within the unit directory, as defined in the *IEEE 1394-1995 Specification*.

### `UnitSwVersion`

On input, the UnitSwVersion value to use within the unit directory, as defined in the *IEEE 1394-1995 Specification*.

### `hCromEntry`

On input, a handle to the Configuration ROM entry.

If ADD-UNIT_DIRECTORY_ENTRY is set in **Flags**, **hCromEntry** is ignored.

If REMOVE_UNIT_DIRECTORY_ENTRY is set in **Flags**, **hCromEntry** is a handle to the Configuration ROM entry to remove.

On output, if ADD_UNIT_DIRECTORY_ENTRY is set in **Flags**, a handle to the newly added unit directory is written to **hCromEntry**.

If REMOVE_UNIT_DIRECTORY_ENTRY is set in Flags, **hCromEntry** is null.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)