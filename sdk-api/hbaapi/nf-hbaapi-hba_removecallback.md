## Description

De-registers a callback routine.

## Parameters

### `callbackHandle`

An opaque handle (that you retrieved when you registered the callback routine) that identifies the callback routine to de-register.

## Return value

A value of type [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the status of the HBA. In particular, it returns one of the following values.

|Return code|Description|
|-|-|
|HBA_STATUS_OK|The callback routine was successfully de-registered.|
|HBA_STATUS_ERROR|An unspecified error occurred that prevented the de-registration of the callback routine.|

## Remarks

## See also