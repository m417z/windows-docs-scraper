# ID3DUserDefinedAnnotation::GetStatus

## Description

Determines whether the calling application is running under a Microsoft Direct3D profiling tool.

## Return value

The return value is nonzero if the calling application is running under a Direct3D profiling tool such as Visual Studio Ultimate 2012, and zero otherwise.

## Remarks

You can call **GetStatus** to determine whether your application is running under a Direct3D profiling tool before you make further calls to other methods of the [ID3DUserDefinedAnnotation](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3duserdefinedannotation) interface. For example, the [ID3DUserDefinedAnnotation::BeginEvent](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3duserdefinedannotation-beginevent) and [ID3DUserDefinedAnnotation::EndEvent](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nf-d3d11_1-id3duserdefinedannotation-endevent) methods have no effect if the calling application is not running under an enabled Direct3D profiling tool. Therefore, you do not need to call these methods unless your application is running under a Direct3D profiling tool.

#### Examples

The following code shows how to use **GetStatus**.

```

#ifdef DEVELOPMENT_BUILD
    if ( pPerf->GetStatus() )
        m_MakeD3DAnnotationCalls = true;
#endif

…

   if ( m_ MakeD3DAnnotationCalls )
        pPerf->BeginEvent(L“Drawing Ocean”);
   MyDrawOceanRoutine();

```

## See also

[ID3DUserDefinedAnnotation](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3duserdefinedannotation)