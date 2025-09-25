# TranslateAxes function

## Description

The TranslateAxes function applies the rotation matrix to the given sample.

## Parameters

### `RotationMatrix`

Supplies the VEC3D buffer in which the rotation matrix is stored.

### `RotationMatrixEntryCount`

Supplies the number of elements that RotationMatrix holds.

### `Data`

Supplies the VEC3D buffer in which input data is stored and in which the transformed data is returned.

### `DataCount`

Supplies the number of elements that Data holds.

## Remarks

The caller is responsible for saving/restoring the floating point context prior to calling this function.

## See also