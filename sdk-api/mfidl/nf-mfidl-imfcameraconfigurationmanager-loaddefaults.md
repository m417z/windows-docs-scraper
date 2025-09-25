## Description

Loads the camera control defaults for the specified capture source.

## Parameters

### `cameraAttributes` [in]

A pointer to an [IMFAttributes](https://learn.microsoft.com/windows/win32/api/mfobjects/nn-mfobjects-imfattributes) in which the [MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK](https://learn.microsoft.com/windows/win32/medfound/mf-devsource-attribute-source-type-vidcap-symbolic-link) attribute identifies the capture source for which default control values are retrieved.

### `configurations` [out]

Receives a pointer to an [IMFCameraControlDefaultsCollection](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameracontroldefaultscollection) object representing the collection of camera control default values.

## Return value

An HRESULT, including the following:

| Value | Description |
|-------|-------------|
| S_OK | Success |
| MF_E_ATTRIBUTENOTFOUND | The MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK attribute was not found in the IMFAttributes provided in *cameraAttributes* |
| MF_E_SHUTDOWN | The function was called after [IMFCameraConfigurationManager::Shutdown](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraconfigurationmanager-shutdown) was called. |

## Remarks

If there are no default controls specified, the resulting collection will be empty. I.e. [IMFCameraControlDefaultsCollection::GetControlCount](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameracontroldefaultscollection-getcontrolcount) will return 0.

## See also