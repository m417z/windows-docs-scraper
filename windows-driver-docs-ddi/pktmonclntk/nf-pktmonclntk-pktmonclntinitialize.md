## Description

The **PktMonClntInitialize** function initializes the Packet Monitor client, informing Packet Monitor about the module ID that identifies the client, as well as some handlers it makes available for Packet Monitor to call.

## Parameters

### `ModuleId`

A network module identifier used to identify the Packet Monitor client.

### `EnumComponents`

A handler that Packet Monitor should call to enumerate components.

```cpp
typedef VOID (NTAPI PKTMON_CLIENT_COMP_ENUM)(VOID);
typedef PKTMON_CLIENT_COMP_ENUM(*PKTMON_CLIENT_COMP_ENUM_HANDLER);
```

### `CleanupComponents`

A handler that Packet Monitor should call to cleanup components. Can be NULL.

```cpp
typedef VOID (NTAPI PKTMON_CLIENT_CLEANUP)(VOID);
typedef PKTMON_CLIENT_CLEANUP(*PKTMON_CLIENT_CLEANUP_HANDLER);
```

### `NotifyComponent`

A handler that Packet Monitor should call to notify a component. Can be NULL.

```cpp
typedef VOID (NTAPI PKTMON_CLIENT_COMP_NOTIFY)(_In_ PKTMON_COMPONENT_CONTEXT *CompContext);
typedef PKTMON_CLIENT_COMP_NOTIFY(*PKTMON_CLIENT_COMP_NOTIFY_HANDLER);
```

## Return value

If the function succeeds, it returns `STATUS_SUCCESS`. Otherwise, it returns a `NTSTATUS` error code.

## Remarks

**PktMonClntInitialize** should only be called once per module. To uninitialize the driver before it exits, call the **[PktMonClntUninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntuninitialize)** function.

## See also

- **[PktMonClntUninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntuninitialize)**

### Example

```cpp
const NPI_MODULEID NPI_PKTMON_CLNT_DRV_MODULEID = {
    sizeof(NPI_MODULEID),
    MIT_GUID,
    {
        0xeb004a00 + 0xea,
        0x9b1a, 0x11d4, {0x91, 0x23, 0x00, 0x50, 0x04, 0x77, 0x59, 0xbc}
    }
};

VOID NTAPI PktMonApiTstRegistrationCallback(VOID)
{
    // NOTE: Can be used to register providers
}

VOID NTAPI PktMonApiTstClientCleanupCallback(VOID)
{
    // Cleanup components
}

VOID NTAPI PktMonApiTstClientCompNotifyCallback(_In_ PKTMON_COMPONENT_CONTEXT *CompContext)
{
    UNREFERENCED_PARAMETER(CompContext);

    // Handle notification
}

NTSTATUS NTAPI DriverEntry(
    _In_ PDRIVER_OBJECT DriverObject,
    _In_ PUNICODE_STRING RegistryPath
)
{
    NTSTATUS status = STATUS_SUCCESS;

    status = PktMonClntInitialize(
        &NPI_PKTMON_CLNT_DRV_MODULEID,
        PktMonApiTstRegistrationCallback,
        PktMonApiTstClientCleanupCallback,
        PktMonApiTstClientCompNotifyCallback
    );
    if (STATUS_SUCCESS != status)
    {
        // Log error
        return status;
    }

    // Additional driver initialization code

    return status;
}
```