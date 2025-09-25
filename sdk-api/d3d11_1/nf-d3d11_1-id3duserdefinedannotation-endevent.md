# ID3DUserDefinedAnnotation::EndEvent

## Description

Marks the end of a section of event code.

## Return value

Returns the number of previous calls to the [ID3DUserDefinedAnnotation::BeginEvent](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3duserdefinedannotation-beginevent) method that have not yet been finalized by calls to **EndEvent**.

The return value is –1 if the calling application is not running under a Direct3D profiling tool.

## Remarks

You call the [BeginEvent](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3duserdefinedannotation-beginevent) method to mark the beginning of the section of event code.

A user can visualize the event when the calling application is running under an enabled Direct3D profiling tool such as Microsoft Visual Studio Ultimate 2012.

**EndEvent** has no effect if the calling application is not running under an enabled Direct3D profiling tool.

## See also

[ID3DUserDefinedAnnotation](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3duserdefinedannotation)