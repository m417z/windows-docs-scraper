# D2DGetInput function

Returns the color of input N at the input coordinate. Only available for simple inputs.

## Parameters

*N* \[in\]

The input number.

## Return value

The function returns a **float4**, containing the RGBA color in the format INPUTN.

## Remarks

The following example shows the function being used as part of an arithmetic composite effect.

``` syntax

D2D_PS_ENTRY(PS_NAME)
{
    MIN_TYPE(float4) sourceColor = D2DGetInput(0);
    MIN_TYPE(float4) destColor   = D2DGetInput(1);

    MIN_TYPE(float4) output = // TODO: add math to composite source and dest

    return output;
}
```

Also, refer to the remarks for [D2D\_PS\_ENTRY](https://learn.microsoft.com/windows/win32/direct2d/d2d-ps-entry) for another example of the use of this function.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------|
| Header<br> | D2d1effecthelpers.hlsli |
| DLL<br> | D2d1.dll |

## See also

[Effect Shader Linking](https://learn.microsoft.com/windows/win32/direct2d/effect-shader-linking)

[HLSL Helpers](https://learn.microsoft.com/windows/win32/direct2d/hlsl-helpers)

