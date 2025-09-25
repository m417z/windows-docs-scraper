# ID3D10Effect::Optimize

## Description

Minimize the amount of memory required for an effect.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An effect uses memory space two different ways: to store the information required by the runtime to execute an effect, and to store the metadata
required to reflect information back to an application using the API. You can minimize the amount of memory required by an effect by
calling **ID3D10Effect::Optimize** which removes the reflection metadata from memory. API methods to read variables will no
longer work once reflection data has been removed.

The following methods will fail after Optimize has been called on an effect.

* [ID3D10Effect::GetConstantBufferByIndex](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getconstantbufferbyindex)
* [ID3D10Effect::GetConstantBufferByName](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getconstantbufferbyname)
* [ID3D10Effect::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getdesc)
* [ID3D10Effect::GetDevice](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getdevice)
* [ID3D10Effect::GetTechniqueByIndex](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-gettechniquebyindex)
* [ID3D10Effect::GetTechniqueByName](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-gettechniquebyname)
* [ID3D10Effect::GetVariableByIndex](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getvariablebyindex)
* [ID3D10Effect::GetVariableByName](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getvariablebyname)
* [ID3D10Effect::GetVariableBySemantic](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effect-getvariablebysemantic)

Note that references retrieved with these methods before calling **ID3D10Effect::Optimize** are still valid
after **ID3D10Effect::Optimize** is called. This allows the application to get all the variables, techniques, and passes it will use,
call Optimize, and then use the effect.

## See also

[ID3D10Effect Interface](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nn-d3d10effect-id3d10effect)