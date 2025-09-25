# ISdoServiceControl::ResetService

## Description

The **ResetService** method resets the
service administered by the SDO API. Resetting the service causes the service to refresh its data.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

The data refresh begins 5 seconds after the last call to
**ISdoServiceControl::ResetService**. The
amount of time it takes for the refresh to complete depends on the number of objects in the SDO configuration
database.

## See also

[ISdoMachineGetServiceSDO](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getservicesdo)

[ISdoServiceControl](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdoservicecontrol)