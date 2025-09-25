# D3D12DDI_BACKGROUND_PROCESSING_MODE_0062 enumeration

## Description

Indicates what level of dynamic profiling and shader recompilation is enabled for background processing.

By default, the runtime will schedule at most one background compilation task at a time, running with idle priority so as to minimize the risk of this work, introducing glitches into the foreground rendering.

Developers and profiling tools can adjust this behavior by using combinations of these enum values.

## Constants

### `D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_ALLOWED`

D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_ALLOWED is the default state, in which drivers may instrument workloads in any manner of their choosing, and may submit CPU tasks (typically PSO recompiles) to the D3D runtime for low priority execution. The goal of this mode is to enable dynamic optimizations, but without impacting foreground rendering performance.

### `D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_ALLOW_INTRUSIVE_MEASUREMENTS`

D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_ALLOW_INTRUSIVE_MEASUREMENTS hints that the driver should prioritize richness and completeness of instrumentation over avoiding glitches, because the rendering currently taking place is being done specifically for training purposes and does not need to execute with usual smooth performance.

This kind of heavy-weight profiling will be used by analysis tools such as PIX. It could also be used by benchmarks to warm the optimization state before taking their actual performance measurements, or directly by games at appropriate times (eg. pre-training the driver by rendering invisible content behind a menu).

### `D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_DISABLE_BACKGROUND_WORK`

D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_DISABLE_BACKGROUND_WORK prevents the execution of background processing tasks. When this flag is first turned on, any already-in-progress tasks will be allowed to run to completion. Tasks that the UMD has submitted but which have not yet started running will be cancelled, and any calls to [QueueProcessingWorkCB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_queueprocessingwork_cb_0062) while already in this state will result in the cancel callback being immediately invoked.

Of course the UMD may choose to skip task submission entirely while in the disabled state, but if it does submit work, the runtime will cancel rather than just failing the submit operation, in order to avoid the UMD having to bother synchronizing between work submission and mode changes.

If the disable flag is turned on at the same time as specifying [D3D12DDI_MEASUREMENTS_ACTION_0062_COMMIT_*](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_measurements_action_0062), any new tasks that the UMD generates in response to the commit request will be allowed to execute before the disable takes effect.

The disable flag is only valid when developer mode is enabled.

### `D3D12DDI_BACKGROUND_PROCESSING_MODE_0062_DISABLE_ALL_PROFILING`

In addition to suspending dynamic shader recompilation, this indicates that the driver should avoid making any behavioral changes that would perturb performance, such as dynamically tuning cache policies or compute dispatch patterns. This is for use during profiling sessions, where an A/B comparison must provide stable timing results.

This flag is only valid when developer mode is enabled.

## Remarks

## See also