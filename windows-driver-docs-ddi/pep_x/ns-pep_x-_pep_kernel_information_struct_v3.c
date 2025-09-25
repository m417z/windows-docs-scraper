typedef struct _PEP_KERNEL_INFORMATION_STRUCT_V3 {
  USHORT                                   Version;
  USHORT                                   Size;
  POHANDLE                                 Plugin;
  PPOFXCALLBACKREQUESTWORKER               RequestWorker;
  PPOFXCALLBACKENUMERATEUNMASKEDINTERRUPTS EnumerateUnmaskedInterrupts;
  PPOFXCALLBACKPROCESSORHALT               ProcessorHalt;
  PPOFXCALLBACKREQUESTINTERRUPT            RequestInterrupt;
  PPOFXCALLBACKCRITICALRESOURCE            TransitionCriticalResource;
  PPOFXCALLBACKPROCESSORIDLEVETO           ProcessorIdleVeto;
  PPOFXCALLBACKPLATFORMIDLEVETO            PlatformIdleVeto;
  PPOFXCALLBACKUPDATEPROCESSORIDLESTATE    UpdateProcessorIdleState;
  PPOFXCALLBACKUPDATEPLATFORMIDLESTATE     UpdatePlatformIdleState;
  PPOFXCALLBACKREQUESTCOMMON               RequestCommon;
} PEP_KERNEL_INFORMATION_STRUCT_V3, *PPEP_KERNEL_INFORMATION_STRUCT_V3;