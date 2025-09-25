# SpbRequestGetController function

## Description

The **SpbRequestGetController** method returns the WDFDEVICE handle to the device object for the SPB controller that the specified I/O request was sent to.

## Parameters

### `SpbRequest` [in]

The [SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles) handle to the I/O request from which to retrieve the WDFDEVICE handle. The SPB controller driver previously received this handle through one of its registered [event callback functions](https://learn.microsoft.com/previous-versions/hh450911(v=vs.85)).

## Return value

**SpbRequestGetController** returns the WDFDEVICE handle that the I/O request was sent to.

## See also

[SPBREQUEST](https://learn.microsoft.com/windows-hardware/drivers/spb/spbcx-object-handles)