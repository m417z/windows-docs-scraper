# IDirectXVideoMemoryConfiguration::GetAvailableSurfaceTypeByIndex

## Description

Retrieves a supported video surface type.

## Parameters

### `dwTypeIndex` [in]

Zero-based index of the surface type to retrieve. Surface types are indexed in order of preference, starting with the most preferred type.

### `pdwType` [out]

Receives a member of the [DXVA2_SurfaceType](https://learn.microsoft.com/windows/win32/api/dxva2api/ne-dxva2api-dxva2_surfacetype) enumeration that specifies the surface type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_MORE_TYPES** | The index was out of range. |

## See also

[IDirectXVideoMemoryConfiguration](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideomemoryconfiguration)

[Supporting DXVA 2.0 in DirectShow](https://learn.microsoft.com/windows/desktop/medfound/supporting-dxva-2-0-in-directshow)