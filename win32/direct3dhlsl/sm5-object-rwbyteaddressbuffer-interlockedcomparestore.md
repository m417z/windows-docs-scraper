# InterlockedCompareStore function

Compares the input to the comparison value, atomically.

## Parameters

*dest* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The destination address.

*compare\_value* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The comparison value.

*value* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The input value.

## Return value

This function does not return a value.

## Remarks

This operation can only be performed on int or uint typed resources and shared memory variables. There are three possible uses for this function. The first is when R is a shared memory variable type. In this case, the function performs the operation on the shared memory register referenced by dest. The second scenario is when R is a resource variable type. In this scenario, the function performs the operation on the resource location referenced by dest. Finally, the third scenario is when R is a local variable type. In this scenario, the function reduces to the operation performed using local operations.

This function is supported in the following types of shaders:

| VS | HS | DS | GS | PS | CS |
|-----|-----|-----|-----|-----|-----|
| x | x | x | x | x | x |

## See also

[RWByteAddressBuffer](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-rwbyteaddressbuffer)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

