# ID3D10Effect::IsOptimized

## Description

Test an effect to see if the reflection metadata has been removed from memory.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the effect is optimized; otherwise **FALSE**.

## Remarks

An effect uses memory space two different ways: to store the information required by the runtime to execute an effect, and to store the metadata required to reflect information back to an application using the API. You can minimize the amount of memory required by an effect by calling [ID3D10Effect::Optimize](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-optimize) which removes the reflection metadata from memory. Of course, API methods to read variables will no longer work once reflection data has been removed.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)