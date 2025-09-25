# IMFSensorTransformFactory::GetTransformCount

## Description

Called by the media pipeline to get the number of transforms provided by the sensor transform.

## Parameters

### `pdwCount` [in]

The number of transforms provided by the sensor transform.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In the current release, chaining of transforms is not supported, so this value should always be 1.

## See also

[IMFSensorTransformFactory](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensortransformfactory)