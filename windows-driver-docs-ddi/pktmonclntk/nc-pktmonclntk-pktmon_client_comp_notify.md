## Description

Callback function that Packet Monitor calls to notify a component of changes to it's tracing enablement.

## Parameters

### `CompContext`

A pointer to a [PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context) structure containing context for the component.

## Remarks

Pass a function pointer of this type in the fourth argument of the [PktMonClntInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntinitialize) function. Packet Monitor calls this callback to notify the component.

## See also

- [PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)
- [PktMonClntInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntinitialize)