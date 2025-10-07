# D3DXMACRO structure

Describes preprocessor definitions used by an effect object.

## Members

**Name**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Preprocessor name.

**Definition**

Type: **[**LPCSTR**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Definition name.

## Remarks

To use **D3DXMACRO**s in more than one line, prefix each new line character with a backslash (like a \#define in the C language). For example:

```
sample=
macro.Name = "DO_CODE_BLOCK";
macro.Definition =
    "/* here is a block of code */\\\n"
    "{ do something ... }\\\n";
```

Notice the 3 backslash characters at the end of the line. The first two are required to output a single '\\', followed by the newline character "\\n". Optionally, you may also want to terminate your lines using "\\\\\\r\\n".

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

[**D3DXCreateEffectFromFile**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxcreateeffectfromfile)

