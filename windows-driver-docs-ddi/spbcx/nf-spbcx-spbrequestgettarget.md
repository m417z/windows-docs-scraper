# SpbRequestGetTarget function

## Description

The **SpbRequestGetTarget** method retrieves the SPBTARGET handle from the specified I/O request.

## Parameters

### `SpbRequest` [in]

An [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request. The SPB controller driver previously received this handle through one of its registered [event callback functions](https://learn.microsoft.com/previous-versions/hh450911(v=vs.85)).

## Return value

**SpbRequestGetTarget** returns an [SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the target device on the bus for the specified I/O request.

## Remarks

The returned SPBTARGET handle is guaranteed to remain valid until the corresponding I/O request is completed.

## See also

[SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)

[SPBTARGET](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)