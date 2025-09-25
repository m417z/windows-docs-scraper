# KsCreatePin2 function

## Description

Passes a connection request to a device, creating a pin instance.

Supported starting in Windows 8.

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

Returns **NOERROR** if successful; otherwise, returns an error code.

## Remarks

This is a new version of the [KsCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatepin) function and uses the device broker to create the handle to the kernel streaming object. In addition, the Component Object Model (COM) [CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize) function must be called before this function is called.

The routine sends an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request to the driver. The driver accepts the request only if the interface, medium, and data format are compatible.

If *Connect*->**PinToHandle** is **NULL**, **KsCreatePin2** creates a pin that the caller can use to send requests to the streaming driver specified in *Connect*->**FilterHandle**. *Connect*->**PinId** determines the type of pin to be created.

## See also

[CoInitialize](https://learn.microsoft.com/windows/win32/api/objbase/nf-objbase-coinitialize)

[IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create)

[KSDATAFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdataformat)

[KSPIN_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_connect)

[KsCreatePin](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatepin)