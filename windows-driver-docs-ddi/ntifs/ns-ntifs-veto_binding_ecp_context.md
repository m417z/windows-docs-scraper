## Description

The **VETO_BINDING_ECP_CONTEXT** structure is the ECP context structure associated with [**GUID_ECP_TYPE_VETO_BINDING**](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps) for vetoing a bind link.

## Members

### `ShouldVetoBinding`

When set true, the bind link is vetoed. When set false, the bind link isn't vetoed.

## Remarks

A filter sitting below *BindFlt* can veto a binding on the system's boot partition only, not on any other partition.

For more information, see [Vetoing a bind link](https://learn.microsoft.com/windows-hardware/drivers/ifs/vetoing-a-bind-link).