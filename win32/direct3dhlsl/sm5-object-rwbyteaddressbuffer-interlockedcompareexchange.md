# InterlockedCompareExchange function

Compares the input to the comparison value and exchanges the result, atomically.

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

*original\_value* \[out\]

Type: **[**UINT**](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The original value.

## Return value

This function does not return a value.

## Remarks

Atomically compares the value in *dest* to *compare\_value*, stores value in *dest* if the values match, returns the original value of *dest* in *original\_value*. This operation can only be performed on **int** or *uint* typed resources and shared memory variables. There are three possible uses for this function. The first is when R is a shared memory variable type. In this case, the function performs the operation on the shared memory register referenced by *dest*. The second scenario is when R is a resource variable type. In this scenario, the function performs the operation on the resource location referenced by *dest*. Finally, the third scenario is when R is a local variable type. In this scenario, the function reduces to the operation performed using local operations. This operation is only available when R is readable and writable.

> [!Note]
> If you call **InterlockedCompareExchange** in a [**for**](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-for) or [**while**](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-while) compute shader loop, to properly compile, you must use the **\[allow\_uav\_condition\]** attribute on that loop.

This function is supported in the following types of shaders:

| VS | HS | DS | GS | PS | CS |
|-----|-----|-----|-----|-----|-----|
| x | x | x | x | x | x |

## See also

[RWByteAddressBuffer](https://learn.microsoft.com/windows/win32/direct3dhlsl/sm5-object-rwbyteaddressbuffer)

[Shader Model 5](https://learn.microsoft.com/windows/win32/direct3dhlsl/d3d11-graphics-reference-sm5)

