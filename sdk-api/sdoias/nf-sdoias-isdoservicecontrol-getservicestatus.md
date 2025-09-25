# ISdoServiceControl::GetServiceStatus

## Description

The **GetServiceStatus** method
retrieves the status of the service being administered through SDO.

## Parameters

### `status` [out]

Pointer to a **LONG** variable that contains the status of the service. The status
is one of the following values.

#### SERVICE_STOPPED

The service is stopped.

#### SERVICE_START_PENDING

The service is starting.

#### SERVICE_STOP_PENDING

The service is shutting down.

#### SERVICE_RUNNING

The service is up and running.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## See also

[ISdoMachine::GetServiceSDO](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdomachine-getservicesdo)

[ISdoServiceControl](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdoservicecontrol)