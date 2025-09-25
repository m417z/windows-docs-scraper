# IMFSensorTransformFactory::GetTransformInformation

## Description

Called by the media pipeline to get information about a transform provided by the sensor transform.

## Parameters

### `TransformIndex` [in]

The index of the transform for which information is being requested. In the current release, this value will always be 0.

### `pguidTransformId` [out]

Gets the identifier for the transform.

### `ppAttributes` [out]

The attribute store to be populated.

### `ppStreamInformation` [out]

A collection of [IMFSensorStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorstream) objects.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSensorTransformFactory](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensortransformfactory)