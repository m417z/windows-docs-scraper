# KsCreatePin function

## Description

The **KsCreatePin** function passes a connection request to a device, creating a pin instance. This function can only be called at **PASSIVE_LEVEL** for kernel-mode clients.

## Parameters

### `FilterHandle` [in]

Specifies the handle of the filter initiating the create request and where the connection will occur.

### `Connect` [in]

Pointer to a [KSPIN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_connect) structure that contains parameters for the requested connection. This should be followed in memory by a [KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat) data structure, describing the data format requested for the connection.

### `DesiredAccess` [in]

Specifies the access desired to the pin. This is typically **GENERIC_READ** or **GENERIC_WRITE**. For data flowing into the pin this value should be set to **GENERIC_WRITE**, and for data flowing out of the pin this should be set to **GENERIC_READ** regardless of the communication method.

### `ConnectionHandle` [out]

Specifies the connection handle passed. The routine fills this in with a handle to the file object of the created connection. This value can then be used to disconnect with the [CloseHandle](https://learn.microsoft.com/windows/win32/api/handleapi/nf-handleapi-closehandle) function.

## Return value

The **KsCreatePin** function returns **STATUS_SUCCESS** if the connection was successful, or it returns an error if the connection failed. Additionally, this Win32 error code (from Winerror.h) can be returned:

## Remarks

The routine sends an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request to the driver. The driver accepts the request only if the interface, medium, and data format are compatible.

If *Connect*->**PinToHandle** is **NULL**, **KsCreatePin** creates a pin the caller can use to send requests to the streaming driver specified in *Connect*->**FilterHandle**. *Connect*->**PinId** determines the pin type of the pin to be created.

## See also

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KSPIN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_connect)