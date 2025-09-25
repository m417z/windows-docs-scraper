# D3D10_SHADER_DEBUG_INFO structure

## Description

Describes the format of the [ID3D10Blob Interface](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nn-d3dcommon-id3d10blob) returned by [D3D10GetShaderDebugInfo](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-d3d10getshaderdebuginfo).

## Members

### `Size`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of this structure.

### `Creator`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to LPCSTR for compiler version.

### `EntrypointName`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to LPCSTR for Entry point name.

### `ShaderTarget`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to LPCSTR for shader target.

### `CompileFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags used to compile.

### `Files`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of included files.

### `FileInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_FILE_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_file_info) structures that has **Files** elements.

### `Instructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of instructions.

### `InstructionInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_INST_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_inst_info) structures that has **Instructions** elements.

### `Variables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of variables.

### `VariableInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_VAR_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_var_info) structures that has **Variables** elements.

### `InputVariables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of variables to initialize before running.

### `InputVariableInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_INPUT_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_input_info) structures that has **InputVariables** elements.

### `Tokens`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of tokens to initialize.

### `TokenInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_TOKEN_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_token_info) structures that has **Tokens** elements.

### `Scopes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of scopes.

### `ScopeInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_SCOPE_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_scope_info) structures that has **Scopes** elements.

### `ScopeVariables`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of variables declared.

### `ScopeVariableInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to array of [D3D10_SHADER_DEBUG_SCOPEVAR_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_scopevar_info) structures that has **Scopes** elements.

### `UintOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to the UINT datastore, all UINT offsets are from this offset.

### `StringOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to the string datastore, all string offsets are from this offset.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)