## Description

The **ACXDRMFORWARD** structure contains the information that the DRM system driver needs in order to forward a DRM content ID to a device that handles protected content.

## Members

### `Flags`

No flag bits are currently defined. Set this member to zero.

### `DeviceObject`

Pointer to the device object, which is a system structure of type DEVICE_OBJECT.

### `FileObject`

Pointer to the file object, which is a system structure of type FILE_OBJECT.

### `Context`

Pointer to context data.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)