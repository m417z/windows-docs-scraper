typedef struct _DXGK_TIMED_OPERATION_INTERFACE {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  NTSTATUS((DXGK_TIMED_OPERATION *Op, const LARGE_INTEGER *Timeout,BOOLEAN OsHandled)              * )TimedOperationStart;
  NTSTATUS((DXGK_TIMED_OPERATION *Op,KPROCESSOR_MODE WaitMode,BOOLEAN Alertable, const LARGE_INTEGER *Interval)              * )TimedOperationDelay;
  NTSTATUS((DXGK_TIMED_OPERATION *Op,PVOID Object,KWAIT_REASON WaitReason,KPROCESSOR_MODE WaitMode,BOOLEAN Alertable, const LARGE_INTEGER *Timeout)              * )TimedOperationWaitForSingleObject;
} DXGK_TIMED_OPERATION_INTERFACE, *PDXGK_TIMED_OPERATION_INTERFACE;