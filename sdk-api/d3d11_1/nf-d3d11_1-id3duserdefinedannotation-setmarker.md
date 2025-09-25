# ID3DUserDefinedAnnotation::SetMarker

## Description

Marks a single point of execution in code.

## Parameters

### `Name` [in]

A **NULL**-terminated **UNICODE** string that contains the name of the marker. The name is not relevant to the operating system. You can choose a name that is meaningful when the calling application is running under the Direct3D profiling tool.
A **NULL** pointer produces undefined results.

## Remarks

A user can visualize the marker when the calling application is running under an enabled Direct3D profiling tool such as Microsoft Visual Studio Ultimate 2012.

**SetMarker** has no effect if the calling application is not running under an enabled Direct3D profiling tool.

#### Examples

The following code shows how to use **SetMarker**.
It also uses the [CComPtr](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2010/ezzw7k98(v=vs.100)) smart pointer type.

```

CComPtr< ID3D11DeviceContext > pID3D11DeviceContext;

HRESULT hrCreateDevice = (*pfnD3D11CreateDevice)(
        0,
        D3D_DRIVER_TYPE_NULL,
        0,
        0,
        NULL,
        0,
        D3D11_SDK_VERSION,
        NULL,
        0,
        & pID3D11DeviceContext );
VERIFY_SUCCEEDED(hrCreateDevice);

CComPtr<ID3DUserDefinedAnnotation> pPerf;
HRESULT hr = pID3D11DeviceContext->QueryInterface( __uuidof(pPerf), reinterpret_cast<void**>(&pPerf) );
if ( FAILED( hr ) )
    return;
pPerf->SetMarker( L”Occlusion test failed- not drawing sun flare” );

```

## See also

[ID3DUserDefinedAnnotation](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3duserdefinedannotation)