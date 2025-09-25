# IOCTL_BTHX_QUERY_CAPABILITIES IOCTL

## Description

IOCTL_BTHX_QUERY_CAPABILITIES is used to query the capabilities of the transport driver.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The **AssociatedIrp.SystemBuffer** member points to a buffer that holds a [BTHX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ns-bthxddi-_bthx_capabilities) structure.

### Output buffer length

The length of the buffer is the size of the **BTHX_CAPABILITIES** structure.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to the size of the structure.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |

## Remarks

During startup, the Bluetooth stack sends IOCTL_BTHX_QUERY_CAPABILITIES to query the capabilities of the transport driver.

This is a synchronous call and failure of this IOCTL prevents Windows from loading the Bluetooth stack.

The output buffer of this IOCTL is defined by the BTHX_CAPABILITIES structure.

The **MaxScoChannels** member must be set to 1. The **ScoSupport** member must be set to **ScoSupportHCIBypass**. Failure to do so prevents the stack from being loaded.