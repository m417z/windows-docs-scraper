# _DEBUG_VALUE structure

## Description

The DEBUG_VALUE structure holds register and expression values.

## Members

### `I8`

See Remarks.

### `I16`

See Remarks.

### `I32`

See Remarks.

### `I64`

See Remarks.

### `Nat`

See Remarks.

### `F32`

See Remarks.

### `F64`

See Remarks.

### `F80Bytes[10]`

See Remarks.

### `F82Bytes[11]`

See Remarks.

### `F128Bytes[16]`

See Remarks.

### `VI8[16]`

See Remarks.

### `VI16[8]`

See Remarks.

### `VI32[4]`

See Remarks.

### `VI64[2]`

See Remarks.

### `VF32[4]`

See Remarks.

### `VF64[2]`

See Remarks.

### `I64Parts32`

See Remarks.

### `I64Parts32.LowPart`

See Remarks.

### `I64Parts32.HighPart`

See Remarks.

### `F128Parts64`

See Remarks.

### `F128Parts64.LowPart`

See Remarks.

### `F128Parts64.HighPart`

See Remarks.

### `RawBytes[32]`

See Remarks.

### `TailOfRawBytes`

See Remarks.

### `Type`

See Remarks.

## Remarks

The **Type** field specifies the value type that is being held by the structure. This also specifies which field in the structure is valid. The possible values of the **Type** field, and the corresponding field specified as valid in the structure, include the following.

| Type Name | Type | Valid DEBUG_VALUE Field |
| --- | --- | --- |
| DEBUG_VALUE_INT8 | 8-bit signed integer | **I8** |
| DEBUG_VALUE_INT16 | 16-bit signed integer | **I16** |
| DEBUG_VALUE_INT32 | 32-bit signed integer | **I32** |
| DEBUG_VALUE_INT64 | 64-bit signed integer | **I64** |
| DEBUG_VALUE_FLOAT32 | 32-bit floating point number | **F32** |
| DEBUG_VALUE_FLOAT64 | 64-bit floating point number | **F64** |
| DEBUG_VALUE_FLOAT80 | 80-bit floating point number | **F80Bytes** |
| DEBUG_VALUE_FLOAT128 | 128-bit floating point number | **F128Bytes** |
| DEBUG_VALUE_VECTOR64 | 64-bit vector | **VI8[8]**, **VI16[4]**, **VI32[2]**, **VI64[1]**, **VF32[2]**, **VF64[1]** |
| DEBUG_VALUE_VECTOR128 | 128-bit vector | **VI8[16]**, **VI16[8]**, **VI32[4]**, **VI64[2]**, **VF32[4]**, **VF64[2]** |