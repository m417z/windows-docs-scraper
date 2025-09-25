# _DXGK_SCHEDULING_LOG_CONTEXT_STATE enumeration

## Description

Describes that event to log when a context transitions between one of its execution states. Context state change events are often accompanied by more specific queue events that result in changing the context state.

## Constants

### `DXGK_SCHEDULING_LOG_CONTEXT_STATE_IDLE`

The context is idle and there is no pending GPU work present on the context.

### `DXGK_SCHEDULING_LOG_CONTEXT_STATE_RUNNING`

The context is currently executing on the GPU.

### `DXGK_SCHEDULING_LOG_CONTEXT_STATE_READY`

The context has pending GPU work, but is not executing on the GPU.

### `DXGK_SCHEDULING_LOG_CONTEXT_STATE_READY_STANDBY`

The context is ready, and the GPU has been informed this context is next to be executed, but the context has not started running yet. This state is not strictly required to be supported by the GPU context management processor, but it is useful for reducing context switch latency.