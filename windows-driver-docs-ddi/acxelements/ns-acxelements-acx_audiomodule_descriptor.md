## Description

The **ACX_AUDIOMODULE_DESCRIPTOR** is used to define an audio module descriptor structure.

## Members

### `ClassId`

The GUID identifier of the module, which is defined by the audio device module owner.

### `InstanceId`

The identifier, defined by the driver developer, that disambiguates between multiple instances of the same module class in the driver topology.

### `VersionMajor`

The major version of the audio module.

### `VersionMinor`

The minor version of the audio module.

### `Name`

The friendly name of the audio device module for display in UI. The buffer size is ACX_AUDIOMODULE_MAX_NAME_CCH_SIZE including the NULL terminator.

## Remarks

### Example

Sample Pending

Example usage is shown below.

```cpp

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)