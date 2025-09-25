# REFS_SMR_VOLUME_GC_ACTION enumeration

## Description

The **REFS_SMR_VOLUME_GC_ACTION** enum contains the available garbage collection commands for [**FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-refs-smr-volume-gc-parameters).

## Constants

### `SmrGcActionStart:1`

Specifies to start garbage collection or resume from a previously paused garbage collection. By default, garbage collection is off on Shingled Magnetic Recording (SMR) volumes. Only users with admin rights can modify this setting.

### `SmrGcActionStartFullSpeed:2`

Specifies to start or resume garbage collection at full speed, issuing Read/Write I/O up to one SMR band size (256mb) at a time.

### `SmrGcActionPause:3`

Specifies to temporarily stop the garbage collection if it's in progress. If the garbage collection is not in progress, there will be no operation.

### `SmrGcActionStop:4`

Specifies to stop the garbage collection process and removes the ability to resume. If garbage collection was paused previously, this will clear the ability to resume from the point of the pause.

## See also

[**FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-set-refs-smr-volume-gc-parameters)