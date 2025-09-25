# FSCTL_OFFLOAD_READ_INPUT structure

## Description

The **FSCTL_OFFLOAD_READ_INPUT** structure contains the input for the [**FSCTL_OFFLOAD_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read) control code request.

## Members

### `Size`

The size in bytes of this structure. Set this member to ```sizeof(FSCTL_OFFLOAD_READ_INPUT)```.

### `Flags`

 This member is not used. Set to 0.

### `TokenTimeToLive`

The time, in milliseconds, for which the read operation remains valid. The default time-to-live is 0. The recommended value for time-to-live is also 0.

### `Reserved`

 Reserved.

### `FileOffset`

 The position in the file to start reading from. The offset value must be aligned to a logical sector boundary on the volume.

### `CopyLength`

 The length, in bytes, of data to read, starting at **FileOffset**. The length value must align to a logical sector boundary on the volume, except when the length matches end-of-file.

## Remarks

The storage device's copy provider retains the data read for the duration in **TokenTimeToLive**. Multiple writes with the same token can be performed until the time in **TokenTimeToLive** expires.

## See also

[**FSCTL_OFFLOAD_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-offload-read)

[**FSCTL_OFFLOAD_READ_OUTPUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsctl_offload_read_output)