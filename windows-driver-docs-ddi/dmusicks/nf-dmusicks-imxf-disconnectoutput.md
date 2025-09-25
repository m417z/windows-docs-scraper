# IMXF::DisconnectOutput

## Description

The DisconnectOutput method disconnects this IMXF interface from the synth sink or capture sink.

## Parameters

### `sinkMXF`

Pointer to the destination (sink) IMXF interface that we are disconnecting from.

## Return value

This method returns NTSTATUS which contains STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code.

## Remarks

This method zeros the pSinkMXF location that was previously filled in by the IMXF::ConnectOutput call.

Output will go to the allocator from the time that DisconnectOutput is called until ConnectOutput is called again.

## See also

[IMXF](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nn-dmusicks-imxf)