# IMFSensorTransformFactory::InitializeFactory

## Description

Called by the media pipeline to initialize the sensor transform.

## Parameters

### `dwMaxTransformCount` [in]

The maximum number of transforms allowed in a single transform. In the current release, this is always 1.

### `pSensorDevices` [in]

A collection of [IMFSensorDevice](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensordevice) objects representing the available sensors.

### `pAttributes` [in, optional]

The attribute store to be populated by the sensor transform. The only required attribute for sensor transforms is [MF_STF_VERSION_INFO](https://learn.microsoft.com/windows/desktop/medfound/mf-stf-version-info).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSensorTransformFactory](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensortransformfactory)