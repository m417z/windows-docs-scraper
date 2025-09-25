# _SET_LOCAL_HOST_PROPS3 structure

## Description

SET_LOCAL_HOST_PROPS3 contains the data necessary for defining or identifying one or more unit directories in the Configuration ROM of a 1394 Host Controller.

## Members

### `fulFlags`

Specifies the action to be taken with the unit directory data contained in the SET_LOCAL_HOST_PROPS3 structure.

| Flag | Description |
| --- | --- |
| SLHP_FLAG_ADD_CROM_DATA | Indicates that the data contained in the SET_LOCAL_HOST_PROPS3 structure is to be used to create a new unit directory in the Host Controller's Configuration ROM. |
| SLHP_FLAG_REMOVE_CROM_DATA | Indicates that the data contained in the SET_LOCAL_HOST_PROPS3 structure is to be used to identify and remove an existing unit directory in the Host Controller's Configuration ROM. |

### `hCromData`

Contains a handle that is returned after one or more unit directories have been created. Drivers must store this value and pass it to the bus driver when removing these unit directories. If the SLHP_FLAG_ADD_CROM_DATA flag is set, then this is an output parameter. If the SLHP_FLAG_REMOVE_CROM_DATA flag is set, then this is an input parameter.

### `nLength`

Contains length of the data buffer pointed to by **Mdl**.

### `Mdl`

Pointer to the data buffer containing the unit directory information.

## Remarks

The SET_LOCAL_HOST_PROPS3 structure is sent to the bus driver in the **u.SetLocalHostProperties.Information** member of an IRB during a [REQUEST_SET_LOCAL_HOST_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request, with **u.SetLocalHostProperties.nLevel=** SET_LOCAL_HOST_PROPERTIES_MODIFY_CROM.

The first element of the buffer pointed to by **Mdl** must be a unit directory. This is followed by offsets to any other leafs or directories defined in the request. The offsets must be relative to the beginning of the buffer. If the request results in the creation of a new unit directory, the bus driver adds a pointer to the newly created directory in the root directory. The buffer pointed to by **Mdl** must be in big-endian data format. If a driver fails to remove its dynamically added Configuration ROM data when the driver is removed, the bus driver does so automatically, restoring the default contents of the Configuration ROM.

## See also

[IEEE1394_API_REQUEST](https://learn.microsoft.com/previous-versions/ff537204(v=vs.85))

[REQUEST_SET_LOCAL_HOST_PROPERTIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)