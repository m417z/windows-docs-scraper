## Description

Saves the provided collection of camera control default values.

## Parameters

### `configurations` [in]

An [IMFCameraControlDefaultsCollection](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontroldefaultscollection) representing the collection of camera control default values to save.

## Return value

An HRESULT, including the following:

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| MF_E_SHUTDOWN | The function was called after [IMFCameraConfigurationManager::Shutdown](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-shutdown) was called. |

## Remarks

The provided default values are assigned to the camera specified with the [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK](https://learn.microsoft.com/windows/win32/medfound/mf-devsource-attribute-source-type-vidcap-symbolic-link) value provided when the collection was loaded with a call to [IMFCameraConfigurationManager::LoadDefaults](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-loaddefaults). Saving an empty collection will clear all existing control default values for the associated camera.

## See also