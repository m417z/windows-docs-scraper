# _ACPI_PLD_JOINT_BUFFER structure

## Description

Describes the ACPI PLD joint descriptor buffer, revision 1 (Microsoft custom PLD buffer extension, 128-bits).

## Members

### `Revision`

### `JointType`

### `SourceEdge`

### `TargetCabinetNumber`

### `TargetPanel`

### `TargetEdge`

### `Reserved1`

### `MovementOrientation`

### `ForwardMovementRange`

### `BackwardMovementRange`

### `HorizontalOffset`

### `VerticalOffset`

### `GapOffset`

### `Rotation`

### `Reserved2`

## Remarks

The GUID is defined as follows:

```cpp
DEFINE_GUID(ACPI_PLD_JOINT_BUFFER_GUID,
    0xf01cfc40, 0x3c75, 0x4523, 0x9e, 0x44, 0x21, 0x5c, 0xb1, 0x54, 0xbd, 0xa6);
```

## See also