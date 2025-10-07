# InterlockedAnd function

Ands the value, atomically.

## Parameters

*dest* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The destination address.

*value* \[in\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The input value.

*original\_value* \[out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The original value.

## Return value

This function does not return a value.

## Remarks

This operation can only be performed on int or uint typed resources and shared memory variables. There are three possible uses for this function. The first is when R is a shared memory variable type. In this case, the function performs an atomic and of value to the shared memory register referenced by dest. The second scenario is when R is a resource variable type. In this scenario, the function performs an atomic and of value to the resource location referenced by dest. Finally, the third scenario is when R is a local variable type. In this scenario, the function reduces to an and of the value of dest and value, stored in dest. The overloaded function has an additional output variable which will be set to the original value of dest. This overloaded operation is only available when R is readable and writable.

This function is supported in the following types of shaders:

| VS | HS | DS | GS | PS | CS |
|-----|-----|-----|-----|-----|-----|
| x | x | x | x | x | x |

## See also

[RWByteAddressBuffer](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-rwbyteaddressbuffer)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

