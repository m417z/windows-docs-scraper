# IoGetRequestorSessionId function

## Description

The **IoGetRequestorSessionId** routine returns the session ID for the process that originally requested a given I/O operation.

## Parameters

### `Irp` [in]

A pointer to the I/O request packet (IRP) for the I/O operation.

### `pSessionId` [out]

A pointer to a caller-allocated variable that receives the session ID for the process that requested the I/O operation. If the call fails (STATUS_UNSUCCESSFUL), this parameter is set to -1.

## Return value

**IoGetRequestorSessionId** returns STATUS_SUCCESS if the session ID is successfully returned, and returns STATUS_UNSUCCESSFUL otherwise. STATUS_UNSUCCESSFUL is an error NTSTATUS value.

## See also

[**IoGetRequestorProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetrequestorprocess)