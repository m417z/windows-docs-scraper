typedef struct _DXGK_SPB_INTERFACE {
  USHORT                 Size;
  USHORT                 Version;
  PVOID                  Context;
  PINTERFACE_REFERENCE   InterfaceReference;
  PINTERFACE_DEREFERENCE InterfaceDereference;
  NTSTATUS(HANDLE DeviceHandle,LARGE_INTEGER SpbReourceId,UNICODE_STRING *SpbResourceSubName,ACCESS_MASK DesiredAccess,ULONG ShareAccess,ULONG OpenOptions,VOID **SpbResource)              * )(OpenSpbResource;
  NTSTATUS()(HANDLE DeviceHandle,VOID *SpbResource)              * CloseSpbResource;
  NTSTATUS(ANDLE DeviceHandle,VOID *SpbResource,ULONG Length,VOID *Buffer,LARGE_INTEGER *ByteOffset,HANDLE EventHandle,IO_STATUS_BLOCK *IoStatusBlock)              * )(HReadSpbResource;
  NTSTATUS(ANDLE DeviceHandle,VOID *SpbResource,ULONG Length,VOID *Buffer,LARGE_INTEGER *ByteOffset,HANDLE EventHandle,IO_STATUS_BLOCK *IoStatusBlock)              * )(HWriteSpbResource;
  NTSTATUS(ANDLE DeviceHandle,VOID *SpbResource,ULONG IoControlCode,ULONG InBufferSize,VOID *InputBuffer,ULONG OutBufferSize,VOID *OutputBuffer,HANDLE EventHandle,IO_STATUS_BLOCK *IoStatusBlock)              * )(HSpbResourceIoControl;
} DXGK_SPB_INTERFACE, *PDXGK_SPB_INTERFACE;