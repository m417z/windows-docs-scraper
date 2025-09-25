## Description

The **PktMonClntAddEdge** function adds an edge to a Packet Monitor component. An edge represents a pair of entry/exit points for a component. It can be referred to as a boundary for a component. Each component optionally registers its lower or/and upper edge.

## Parameters

### `CompContext`

Pointer to the **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)** structure that holds the context for the component.

### `Name`

The name of the edge being added.

### `PacketType`

Packet type to be handled by this edge. Must be a valid value defined in **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**.

### `EdgeContext`

Pointer to a **[PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)** which will store the context information for this edge.

## Return value

If the function succeeds, it returns `STATUS_SUCCESS`. Otherwise, it returns a `NTSTATUS` error code.

## Remarks

An edge represents a pair of entry and exit points for a component. It can be referred to as a boundary for a component. Each component optionally registers its lower and upper edge. A component can have multiple edges. One call to **PktMonClntAddEdge** should be made for each of these edges.

The *ListLink* member of **[PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)** is used to track all the edge contexts belonging to a component. *ListLink* can be used to access these edge contexts.

## See also

- **[PKTMON_PACKET_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ne-pktmonnpik-pktmon_packet_type)**
- **[PKTMON_EDGE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_edge_context)**

### Example

```cpp
PKTMON_EDGE_CONTEXT EdgeContext = { 0 };

NTSTATUS
NTAPI
PktMonApiTstAddEdge()
{
    NTSTATUS status = STATUS_SUCCESS;

    DECLARE_CONST_UNICODE_STRING(EdgeName, L"LowerEdge");

    status = PktMonClntAddEdge(
        &PktMonComp,
        &EdgeName,
        PktMonPayload_IP,
        &EdgeContext
    );
    if (STATUS_SUCCESS != status)
    {
        return status;
    }

    return status;
}
```