## Description

The **PktMonClntUninitialize** function uninitializes the kernel driver that is acting as a Packet Monitor client and was previously initialized through **[PktMonClntInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntinitialize)**.

## Remarks

This function unregisters components that were previously registered by the client and have not been unregistered up to that point. This allows Packet Monitor to free resources that will not be used anymore.

## See also

- **[PktMonClntInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntinitialize)**

### Example
```cpp
VOID
PktMonApiTstUnload(
    _In_ PDRIVER_OBJECT DriverObject
    )
{
    ...
    PktMonClntUninitialize();
    ...
}
```