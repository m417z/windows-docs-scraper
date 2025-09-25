# IOCTL_BTHX_GET_VERSION IOCTL

## Description

Profile drivers use IOCTL_BTHX_GET_VERSION to get the version supported by the transport driver.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

Profile drivers should use KMDF and its [WdfRequestRetrieveOutputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveoutputmemory) method to retrieve output parameters. For example, to get the output buffer:

`Status = WdfRequestRetrieveOutputMemory(_Request, &ReqOutMemory);`

The buffer describes a [BTHX_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ns-bthxddi-_bthx_version) structure.

Refer to the WDK Bluetooth samples for more information.

### Output buffer length

The length of the buffer is the size of the **BTHX_VERSION** structure.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the buffer that holds the BTHX_VERSION structure.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |

Any unsuccessful NT status code prevents the driver from loading.

## Remarks

IOCTL_BTHX_GET_VERSION is a synchronous operation.

A transport driver can return one or more versions that it supports in BTHX_VERSION structure. If no version is set, Windows unloads the Bluetooth stack.