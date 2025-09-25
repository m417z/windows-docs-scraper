typedef struct _WSPUPCALLTABLE {
  LPWPUCLOSEEVENT               lpWPUCloseEvent;
  LPWPUCLOSESOCKETHANDLE        lpWPUCloseSocketHandle;
  LPWPUCREATEEVENT              lpWPUCreateEvent;
  LPWPUCREATESOCKETHANDLE       lpWPUCreateSocketHandle;
  LPWPUFDISSET                  lpWPUFDIsSet;
  LPWPUGETPROVIDERPATH          lpWPUGetProviderPath;
  LPWPUMODIFYIFSHANDLE          lpWPUModifyIFSHandle;
  LPWPUPOSTMESSAGE              lpWPUPostMessage;
  LPWPUQUERYBLOCKINGCALLBACK    lpWPUQueryBlockingCallback;
  LPWPUQUERYSOCKETHANDLECONTEXT lpWPUQuerySocketHandleContext;
  LPWPUQUEUEAPC                 lpWPUQueueApc;
  LPWPURESETEVENT               lpWPUResetEvent;
  LPWPUSETEVENT                 lpWPUSetEvent;
  LPWPUOPENCURRENTTHREAD        lpWPUOpenCurrentThread;
  LPWPUCLOSETHREAD              lpWPUCloseThread;
} WSPUPCALLTABLE, *LPWSPUPCALLTABLE;