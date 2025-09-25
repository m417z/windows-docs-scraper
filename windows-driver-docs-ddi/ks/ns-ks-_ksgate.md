# _KSGATE structure

## Description

The KSGATE structure describes an AVStream gate object.

## Members

### `Count`

This member indicates the count on the gate. When this member is above zero, the gate is considered to be in the "open" state and allows processing. When the member is zero or below, the gate is considered to be in the "closed" state and does not allow processing. Although the KSGATE structure is the universal gate implementation in AVStream, conceptually, there are both AND and OR gates. For AND gates, Count is one minus the number of off inputs to the gate. For OR gates, Count is the number of on inputs for the gate. Thus, in general, this member can contain any value; however, for AND gates, it can only contain values of one or less, and for OR gates, it can only contain values of zero or greater. Clients should be careful not to specifically set the Count member to an invalid value for the given conceptual gate this structure represents.

### `NextGate`

A pointer to the next KSGATE structure in the gate chain. There are restrictions on this propagation using the KsGateXxxAnd and KsGateXxxOr functions. NextGate for an AND gate must point to an OR gate, and for an OR gate must point to an AND gate. Clients can specify state transitions manually via KsGateInitialize instead of KsGateInitializeAnd or KsGateInitializeOr.

## Remarks

Conceptually, flow control gates are logical AND and OR gates; in AVStream, they are used as a processing-control mechanism. For more information, see [Flow Control Gates in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/flow-control-gates-in-avstream).

All of the manipulations of **Count** are done using interlocked functions to provide synchronous state changes. There is no distinction as to whether a given KSGATE represents an AND gate or an OR gate. Thus, clients should be careful not to transition a gate into an invalid state by using **KSGATE***Xxx***And** functions on an OR gate or **KSGATE***Xxx***Or** functions on an AND gate or by using **KsGateTurnInput***Xxx* functions invalidly.

## See also

[KSGATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksgate)

[KsGateInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitialize)

[KsGateInitializeAnd](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeand)

[KsGateInitializeOr](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksgateinitializeor)