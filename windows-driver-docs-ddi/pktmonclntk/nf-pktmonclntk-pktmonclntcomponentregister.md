## Description

The **PktMonClntComponentRegister** function registers a component with Packet Monitor, allowing it to monitor and report packet activities.

## Parameters

### `CompContext`

Pointer to the **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)** that holds the context for the component. Zero-initialize this structure before calling **PktMonClntComponentRegister**, which fills in the structure.

### `Name`

The Packet Monitor component's name.

### `Description`

A description for the Packet Monitor component.

### `Type`

The type associated with this component. This must be one of the values defined in the **[PKTMON_COMPONENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_type)** enumeration.

### `PacketType`

The packet type this client deals with. This must be one of the values defined in the **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)** enumeration.

## Return value

If the function succeeds, it returns `STATUS_SUCCESS`. Otherwise, it returns a `NTSTATUS` error code.

## Remarks

When the component is no longer needed, the Packet Monitor client should call **[PktMonClntComponentUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentunregister)** to unregister it from Packet Monitor and free any associated resources.

## See also

- **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)**
- **[PKTMON_COMPONENT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmondefk/ne-pktmondefk-pktmon_component_type)**
- **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**
- **[PktMonClntComponentUnregister](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntcomponentunregister)**

### Example

```cpp
PKTMON_COMPONENT_CONTEXT PktMonComp = { 0 };

NTSTATUS
PktMonApiTstRegisterComponent(VOID)
{
    NTSTATUS status = STATUS_SUCCESS;

    DECLARE_CONST_UNICODE_STRING(DriverName, L"pktmonapitst.sys");
    DECLARE_CONST_UNICODE_STRING(Description, L"Sample driver to report packet drops to pktmon.sys");

    status = PktMonClntComponentRegister(
        &PktMonComp,
        &DriverName,
        &Description,
        PktMonComp_IpInterface,
        PktMonPayload_IP);

if (!NT_SUCCESS(status)) {
        // Log error
    }

    return status;
}
```