# WdfRequestGetRequestorMode function

## Description

[Applies to KMDF and UMDF]

The **WdfRequestGetRequestorMode** method returns the processor access mode of the originator of a specified I/O request.

## Parameters

### `Request` [in]

A handle to a framework request object.

## Return value

**WdfRequestGetRequestorMode** returns **KernelMode** if the originator of the I/O request is executing in kernel mode. Otherwise, this method returns **UserMode**. The **KernelMode** and **UserMode** constants are defined in *wdm.h*.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about **WdfRequestGetRequestorMode**, see [Obtaining Information About an I/O Request](https://learn.microsoft.com/windows-hardware/drivers/wdf/obtaining-information-about-an-i-o-request).

#### Examples

The following code example is from the [NDISProt](https://learn.microsoft.com/windows-hardware/drivers/wdf/sample-kmdf-drivers) sample driver. This example checks for a valid MAC address if the I/O request came from a user-mode application.

```cpp
//
// To prevent applications from sending packets with spoofed MAC address,
// perform the following check to make sure the source address
// in the packet is the same as the current MAC address of the NIC.
//
if ((WdfRequestGetRequestorMode(Request) == UserMode) &&
    !NPROT_MEM_CMP(pEthHeader->SrcAddr, pOpenContext->CurrentAddress, NPROT_MAC_ADDR_LEN))
{
    DEBUGP(DL_WARN, ("Write: Failing with invalid Source address"));
    NtStatus = STATUS_INVALID_PARAMETER;
    break;
}
```