# IMFDeviceTransform::InitializeTransform

## Description

**InitializeTransform** is called to initialize the Device MFT.

## Parameters

### `pAttributes` [in]

Contains a pointer to an attribute, passed in by the capture pipeline that contains initialization parameters. The following attributes values are passed to the function

| Attribute Key | Description |
| --- | --- |
| **MF_DEVICEMFT_CONNECTED_FILTER_KSCONTROL** | The IKsControl interface of the preceding DeviceTransform object. It also implements IMFDeviceTransform, used to get necessary information needed to create a valid pipeline. |
| **MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK** | Denotes the symbolic link for a video capture driver |
| **MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME** | Specifies the display name for a device. The display name is a human-readable string, suitable for display in a user interface. |

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Initialization succeeded |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |

## Remarks

Device MFTs can take advantage of this function to initialize various internal objects and states. Pipeline can also use the input *IMFAttributes* parameter to communicate certain configuration information to the Device MFT.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)