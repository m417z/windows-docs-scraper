# IOCTL_BTHX_SET_VERSION IOCTL

## Description

IOCTL_BTHX_SET_VERSION is used to inform the transport driver of the version of the extensibility interface being used.

## Parameters

### Major code

### Input buffer

Profile drivers should use KMDF and its [WdfRequestRetrieveInputMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestretrieveinputmemory) method to retrieve input parameters. For example, to get the input buffer:

`Status = WdfRequestRetrieveInputMemory(_Request, &ReqInMemory);`

The buffer describes a [BTHX_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ns-bthxddi-_bthx_version) structure.

Refer to the WDK Bluetooth samples for more information.

### Input buffer length

The length of the buffer is the size of the **BTHX_VERSION** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to zero because the Bluetooth driver
stack returns no data with this IOCTL.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |

Any unsuccessful NT status code prevents the driver from loading.

## Remarks

IOCTL_BTHX_SET_VERSION is a synchronous operation.

Only one version will be selected and set.