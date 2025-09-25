# GetRotationMatrixFromAcpi function

## Description

The GetRotationMatrixFromAcpi function reads the rotation matrix from the ACPI entries.

## Parameters

### `Device`

Supplies the WDF device object.

### `MethodName`

Supplies the method name to read.

### `MethodNameLength`

Supplies the method name length in bytes.

### `RotationMatrix`

Supplies the VEC3D buffer in which the rotation matrix is read.

### `RotationMatrixEntries`

Supplies the number of elements that RotationMatrix can hold.

## Return value

This function returns NTSTATUS.

## Remarks

The caller is responsible for saving/restoring the floating point context prior to calling this function.

## See also