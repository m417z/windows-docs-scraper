# IMFSensorGroup::GetSensorGroupAttributes

## Description

Gets the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) for the sensor group. The returned object is a live reference to the internal attribute store.

## Parameters

### `ppAttributes` [out]

The [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface representing the internal attribute store of the sensor group.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *ppAttributes* parameter is null. |
| **MF_E_NOT_INITIALIZED** | The sensor group has not been initialized. |

## Remarks

The caller may optionally use this attribute store to query for attributes set on the sensor group or modify/add attributes to the sensor group. Modification of this attribute set is not persisted and will only be valid for the instance of the [IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup).

This attribute store can be used to add runtime attributes for the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) that can be created using the [IMFSensorGroup::CreateMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsensorgroup-createmediasource) method.

## See also

[IMFSensorGroup](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorgroup)