# D2DGetScenePosition function

Returns the value of the input SCENE\_POSITION. Only available when D2D\_REQUIRES\_SCENE\_POSITION is declared in the source file.

## Parameters

This function has no parameters.

## Return value

The function returns a **float4** in the format SCENE\_POSITION.

## Remarks

The following example shows the use of the function in generating a dissolve pattern.

``` syntax
D2D_PS_ENTRY(BlendDissolve)
{
    min16float4 dest   = D2DGetInput(0);
    min16float4 source = D2DGetInput(1);

    min16float4 color = dest;

    if ((source.a > 0.0) && (source.a >= Rand((min16float2)D2DGetScenePosition().xy)))
    {
        // TODO: perform  dissolve math
    }

    return color;
}
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------------------|
| Header<br> | D2d1effecthelpers.hlsli |
| DLL<br> | D2d1.dll |

## See also

[Effect Shader Linking](https://learn.microsoft.com/windows/win32/direct2d/effect-shader-linking)

[HLSL Helpers](https://learn.microsoft.com/windows/win32/direct2d/hlsl-helpers)

