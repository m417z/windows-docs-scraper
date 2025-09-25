# IMXF::ConnectOutput

## Description

The ConnectOutput method connects this IMXF interface with the sink specified by the pSinkMXF parameter.

## Parameters

### `sinkMXF`

Pointer to the destination (sink) IMXF interface we are connecting to in the port driver.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

## See also

[IMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imxf)