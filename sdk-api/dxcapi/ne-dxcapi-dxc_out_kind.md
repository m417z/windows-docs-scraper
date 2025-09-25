## Description

Defines constants that specify the kind of output to retrieve from an [IDxcResult](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcresult). For use with the *dxcOutKind* parameter of [IDxcResult::GetOutput](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxcresult-getoutput) and [IDxcResult::HasOutput](https://learn.microsoft.com/windows/win32/api/dxcapi/nf-dxcapi-idxcresult-hasoutput).

> [!NOTE]
> Text outputs returned from version 2 APIs are UTF-8 or UTF-16, depending on the `-encoding` option passed to the compiler.

## Constants

### `DXC_OUT_NONE:0`

Specifies no output.

### `DXC_OUT_OBJECT:1`

For [IDxcBlob](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblob), specifies a shader or library object.

### `DXC_OUT_ERRORS:2`

For [IDxcBlobUtf8](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf8) or [IDxcBlobUtf16](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf16), specifies errors.

### `DXC_OUT_PDB:3`

For [IDxcBlob](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblob), specifies PDB.

### `DXC_OUT_SHADER_HASH:4`

For [IDxcBlob](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblob), specifies the DxcShaderHash of a shader or a shader with source info (`-Zsb/-Zss`).

### `DXC_OUT_DISASSEMBLY:5`

For [IDxcBlobUtf8](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf8) or [IDxcBlobUtf16](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf16), specifies the output from disassembling.

### `DXC_OUT_HLSL:6`

For [IDxcBlobUtf8](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf8) or [IDxcBlobUtf16](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf16), specifies the output from the preprocessor or rewriter.

### `DXC_OUT_TEXT:7`

For [IDxcBlobUtf8](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf8) or [IDxcBlobUtf16](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblobutf16), specifies other text, such as `-ast-dump` or `-Odump`.

### `DXC_OUT_REFLECTION:8`

For [IDxcBlob](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblob), specifies the RDAT part with reflection data.

### `DXC_OUT_ROOT_SIGNATURE:9`

For [IDxcBlob](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcblob), specifies serialized root signature output.

### `DXC_OUT_EXTRA_OUTPUTS:10`

For [IDxcExtraOutputs](https://learn.microsoft.com/windows/win32/api/dxcapi/ns-dxcapi-idxcextraoutputs), specifies extra outputs.

### `DXC_OUT_FORCE_DWORD:0xFFFFFFFF`

## Remarks

## See also