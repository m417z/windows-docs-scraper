typedef struct D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_PROCESS_0088 {
  PFND3D12DDI_CLOSECOMMANDLIST                        pfnCloseCommandList;
  PFND3D12DDI_RESETCOMMANDLIST_0040                   pfnResetCommandList;
  PFND3D12DDI_DISCARD_RESOURCE_0003                   pfnDiscardResource;
  PFND3D12DDI_SET_MARKER                              pfnSetMarker;
  PFND3D12DDI_SET_PREDICATION                         pfnSetPredication;
  PFND3D12DDI_BEGIN_END_QUERY_0003                    pfnBeginQuery;
  PFND3D12DDI_BEGIN_END_QUERY_0003                    pfnEndQuery;
  PFND3D12DDI_RESOLVE_QUERY_DATA                      pfnResolveQueryData;
  PFND3D12DDI_RESOURCEBARRIER_0022                    pfnResourceBarrier;
  PFND3D12DDI_VIDEO_PROCESS_FRAME_0043                pfnProcessFrame;
  PFND3D12DDI_SETPROTECTEDRESOURCESESSION_0030        pfnSetProtectedResourceSession;
  PFND3D12DDI_WRITEBUFFERIMMEDIATE_0032               pfnWriteBufferImmediate;
  PFND3D12DDI_INITIALIZE_VIDEO_EXTENSION_COMMAND_0063 pfnInitializeVideoExtensionCommand;
  PFND3D12DDI_EXECUTE_VIDEO_EXTENSION_COMMAND_0063    pfnExecuteVideoExtensionCommand;
  PFND3D12DDI_BARRIER_0088                            pfnBarrier;
} D3D12DDI_COMMAND_LIST_FUNCS_VIDEO_PROCESS_0088;