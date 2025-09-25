# REFS_SMR_VOLUME_GC_PARAMETERS structure

## Description

The **REFS_SMR_VOLUME_GC_PARAMETERS** structure is used as the input structure for [**FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-refs-smr-volume-gc-parameters).

## Members

### `Version`

The current version of **REFS_SMR_VOLUME_GC_PARAMETERS**. This field should be set to **REFS_SMR_VOLUME_GC_PARAMETERS_VERSION_V1**.

### `Flags`

Specifies the flags. Flags is currently ignored.

### `Action`

Specifies the garbage collection action.

### `Method`

Specifies the garbage collection method or strategy. Currently only **MsSmrGcMethodCompaction** is allowed.

### `IoGranularity`

Specifies the volume's granularity. **IoGranularity** is a multiple of the cluster size up to the Shingled Magnetic Recording (SMR) band size (256 MB). Zero or non-multiple of cluster size will result in a **STATUS_INVALID_PARAMETERS** status.

### `CompressionFormat`

Reserved for future use.

### `Unused`

Reserved for future use.

## See also

[**FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-refs-smr-volume-gc-parameters)