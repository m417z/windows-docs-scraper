# FltIsVolumeSnapshot function

## Description

The **FltIsVolumeSnapshot** routine determines whether a volume or minifilter driver instance is attached to a snapshot volume.

## Parameters

### `FltObject` [in]

An opaque pointer to the volume or instance.

### `IsSnapshotVolume` [out]

A pointer to a caller-allocated Boolean variable that receives **TRUE** if the volume or instance is attached to a snapshot volume. Otherwise, the variable receives **FALSE**.

## Return value

**FltIsVolumeSnapshot** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | **FltIsVolumeSnapshot** determined whether *FltObject* is a snapshot. |
| **STATUS_INVALID_PARAMETER** | *FltObject* specifies something besides a volume or an instance. This is an error code. |
| **STATUS_FLT_NO_DEVICE_OBJECT** | *FltObject* does not have an associated disk device object. This can occur if *FltObject* is associated with a network drive. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltIsVolumeSnapshot** encountered a memory allocation failure. This is an error code. |

## Remarks

If the volume or instance object does not support snapshots, **FltIsVolumeSnapshot** returns STATUS_SUCCESS and *IsSnapshotVolume* is **FALSE**.