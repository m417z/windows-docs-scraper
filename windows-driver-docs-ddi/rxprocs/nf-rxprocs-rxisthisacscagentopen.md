# RxIsThisACscAgentOpen function

## Description

**RxIsThisACscAgentOpen** determines if a file open was made by a user-mode client-side caching agent.

## Parameters

### `RxContext` [in]

A pointer to the RX_CONTEXT structure.

## Return value

**RxIsThisACscAgentOpen** returns **TRUE** on success or **FALSE** on failure.

## Remarks

**RxIsThisACscAgentOpen** is not useful for third-party network mini-redirectors since they cannot integrate into the existing client-side caching infrastructure.

The **RxIsThisACscAgentOpen** routine is called internally by RDBSS when initializing a V_NET_ROOT structure. A network mini-redirector integrated with client-side caching might call **RxIsThisACscAgentOpen** as part of the **MRxCreateVNetRoot** callback routine provided by the network mini-redirector.

## See also

[RX_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxcontx/ns-rxcontx-_rx_context)

[The V_NET_ROOT Structure](https://learn.microsoft.com/windows-hardware/drivers/ifs/the-v-net-root-structure)