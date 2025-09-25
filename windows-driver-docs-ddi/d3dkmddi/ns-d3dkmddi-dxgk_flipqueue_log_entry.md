## Description

In the [hardware flip queue model](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue), the **DXGK_FLIPQUEUE_LOG_ENTRY** structure contains a single flip queue log entry for a completed or cancelled flip.

## Members

### `PresentId`

[in] Identifies the completed or cancelled flip.

### `PresentTimestamp`

[in] Time stamp of the flip. This value is specified in CPU clock counter units (obtained from obtained from [**KeQueryPerformanceCounter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)). **PresentTimestamp** can be one of the following values:

| Value | Meaning |
| ----- | ------- |
| **DXGK_HWFLIPQUEUE_TIMESTAMP_CANCELLED** | The flip was cancelled and contents were never displayed on the screen. |
| Value > 0 | The time stamp when the flip started being visible on the screen; that is, the scanout's start time. |

## Remarks

The [**DXGKARG_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setflipqueuelogbuffer) structure contains a pointer to an array of **DXGK_FLIPQUEUE_LOG_ENTRY** structures.

## See also

[**DXGKARG_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_setflipqueuelogbuffer)

[**DXGKDDI_SETFLIPQUEUELOGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setflipqueuelogbuffer)