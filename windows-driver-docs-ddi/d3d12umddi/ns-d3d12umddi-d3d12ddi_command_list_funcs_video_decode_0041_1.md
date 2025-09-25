# D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_DECODE_0041_1 structure

## Description

Command list functions for video decode.

## Members

### `pfnCloseCommandList`

Close command list.

### `pfnResetCommandList`

Reset command list.

### `pfnDiscardResource`

Discard resource.

### `pfnSetMarker`

Set marker.

### `pfnSetPredication`

Set predication.

### `pfnBeginQuery`

Begin query.

### `pfnEndQuery`

End query.

### `pfnResolveQueryData`

Resolve query data.

### `pfnResourceBarrier`

Resource barrier.

### `pfnDecodeFrame`

Decode frame.

### `pfnSetProtectedResourceSession`

Set protected resource session.

### `pfnWriteBufferImmediate`

Write buffer immediate.

## Syntax

```cpp
typedef struct D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_DECODE_0041_1
{
    PFND3D12DDI_CLOSECOMMANDLIST                            pfnCloseCommandList;
    PFND3D12DDI_RESETCOMMANDLIST_0040                       pfnResetCommandList;
    PFND3D12DDI_DISCARD_RESOURCE_0003                       pfnDiscardResource;
    PFND3D12DDI_SET_MARKER                                  pfnSetMarker;
    PFND3D12DDI_SET_PREDICATION                             pfnSetPredication;
    PFND3D12DDI_BEGIN_END_QUERY_0003                        pfnBeginQuery;
    PFND3D12DDI_BEGIN_END_QUERY_0003                        pfnEndQuery;
    PFND3D12DDI_RESOLVE_QUERY_DATA                          pfnResolveQueryData;
    PFND3D12DDI_RESOURCEBARRIER_0022                        pfnResourceBarrier;
    PFND3D12DDI_VIDEO_DECODE_FRAME_0041_1                   pfnDecodeFrame;
    PFND3D12DDI_SETPROTECTEDRESOURCESESSION_0030            pfnSetProtectedResourceSession;
    PFND3D12DDI_WRITEBUFFERIMMEDIATE_0032                   pfnWriteBufferImmediate;
} D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_DECODE_0041_1;
```