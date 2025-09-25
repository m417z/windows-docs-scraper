# ISdoServiceControl::StartService

## Description

The
**StartService** method starts the service administered through SDO.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## Remarks

Calls to this method return almost immediately. NPS (IAS) takes several minutes to start up if its SDO configuration database contains a large number of objects.

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008.

## See also

[ISdoMachineGetServiceSDO](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getservicesdo)

[ISdoServiceControl](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdoservicecontrol)

[ISdoServiceControl::GetServiceStatus](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdoservicecontrol-getservicestatus)

[ISdoServiceControl::StopService](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdoservicecontrol-stopservice)