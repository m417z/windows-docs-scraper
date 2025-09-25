## Description

The **ACXDRMRIGHTS** structure specifies the DRM content rights assigned to an ACX audio pin or to a driver's stream object.

## Members

### `CopyProtect`

Specifies one of the following copy-protection values:

**TRUE** Enables copy protection.

An audio application must not do the following:

- Store the content in any form in any nonvolatile storage.

- Pass the content by reference or by value to any other component within the host system that is not authenticated by the DRM system.

**FALSE** Disables copy protection. Content can be copied without restrictions.

### `Reserved`

Reserved for future use. Initialize to zero.

### `DigitalOutputDisable`

Specifies one of the following digital output protection values:

**TRUE** Disable digital outputs. A software component must not transfer the content out of the host system through any type of digital interface. Note that digital output protection does not affect USB devices because the host system includes USB devices.

**FALSE** Enables digital outputs. Content can be transferred from the host system to an external component without restrictions.

## Remarks

If the driver supports DRMRIGHTS and also implements a proprietary copy protection mechanism, the driver must aggregate the result of the proprietary implementation with the values of CopyProtect and DigitalOutputDisable to determine the final copy protection state. The final copy protection state must be the most restrictive of all outstanding copy protection requests.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)