# KSDEGRADE structure

The **KSDEGRADE** structure contains specifics of degradation strategies.

> [!NOTE]
> The **KSDEGRADE** typedef is an alias for the [**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier) structure. As such, their definitions are identical.

## Members

`Set`

Specifies the globally unique set identifier.

`Id`

Specifies the set-specific identifier for an item within the set.

`Flags`

Contains a ULONG value that specifies either the current percentage of degradation, expressed in parts per thousand (where a value of 1000 represents no degradation), or specifies the amount of time in native units as specified by the interface.

## Remarks

The **Flags** member can contain different values based on the type of signal degradation that the client employs. See [Quality Management](https://learn.microsoft.com/windows-hardware/drivers/stream/quality-management) for more details on different strategies for solving quality management problems by reducing signal quality.

Because **Flags** contains a ULONG value, multiple Skip requests may be needed to remedy a quality management issue.

## Requirements

**Header:** ks.h (include Ks.h)

## See also

[**KSIDENTIFIER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksidentifier)

[**KSDEGRADE_STANDARD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksdegrade_standard)

[**KSPROPERTY_STREAM_RATECAPABILITY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-stream-ratecapability)

[**KSPROPERTY_STREAM_TIMEFORMAT**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-stream-timeformat)

[Quality Management](https://learn.microsoft.com/windows-hardware/drivers/stream/quality-management)