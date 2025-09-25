# D3D_BLOB_PART enumeration

## Description

Values that identify parts of the content of an arbitrary length data buffer.

## Constants

### `D3D_BLOB_INPUT_SIGNATURE_BLOB`

The blob part is an input signature.

### `D3D_BLOB_OUTPUT_SIGNATURE_BLOB`

The blob part is an output signature.

### `D3D_BLOB_INPUT_AND_OUTPUT_SIGNATURE_BLOB`

The blob part is an input and output signature.

### `D3D_BLOB_PATCH_CONSTANT_SIGNATURE_BLOB`

The blob part is a patch constant signature.

### `D3D_BLOB_ALL_SIGNATURE_BLOB`

The blob part is all signature.

### `D3D_BLOB_DEBUG_INFO`

The blob part is debug information.

### `D3D_BLOB_LEGACY_SHADER`

The blob part is a legacy shader.

### `D3D_BLOB_XNA_PREPASS_SHADER`

The blob part is an XNA prepass shader.

### `D3D_BLOB_XNA_SHADER`

The blob part is an XNA shader.

### `D3D_BLOB_PDB`

The blob part is program database (PDB) information.

**Note** This value is supported by the D3dcompiler_44.dll or later version of the file.

### `D3D_BLOB_PRIVATE_DATA`

The blob part is private data.

**Note** This value is supported by the D3dcompiler_44.dll or later version of the file.

### `D3D_BLOB_ROOT_SIGNATURE`

The blob part is a root signature. Refer to [Specifying Root Signatures in HLSL](https://learn.microsoft.com/windows/desktop/direct3d12/specifying-root-signatures-in-hlsl) for more information on using Direct3D12 with HLSL.

**Note** This value is supported by the D3dcompiler_47.dll or later version of the file.

### `D3D_BLOB_DEBUG_NAME`

The blob part is the debug name of the shader. If the application does not specify the debug name itself, an auto-generated name matching the PDB file of the shader is provided instead.

**Note** This value is supported by the D3dcompiler_47.dll as available on the Windows 10 Fall Creators Update and its SDK, or later version of the file.

### `D3D_BLOB_TEST_ALTERNATE_SHADER:0x8000`

The blob part is a test alternate shader.

**Note** This value identifies a test part and is only produced by special compiler versions. Therefore, this part type is typically not present in shaders.

### `D3D_BLOB_TEST_COMPILE_DETAILS`

The blob part is test compilation details.

**Note** This value identifies a test part and is only produced by special compiler versions. Therefore, this part type is typically not present in shaders.

### `D3D_BLOB_TEST_COMPILE_PERF`

The blob part is test compilation performance.

**Note** This value identifies a test part and is only produced by special compiler versions. Therefore, this part type is typically not present in shaders.

### `D3D_BLOB_TEST_COMPILE_REPORT`

The blob part is a test compilation report.

**Note** This value identifies a test part and is only produced by special compiler versions. Therefore, this part type is typically not present in shaders.

**Note** This value is supported by the D3dcompiler_44.dll or later version of the file.

## Remarks

These values are passed to the [D3DGetBlobPart](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dgetblobpart) or [D3DSetBlobPart](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dsetblobpart) function.

## See also

[Enumerations](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-enums)