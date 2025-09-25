typedef struct _WDF_REQUEST_PARAMETERS {
  USHORT           Size;
  UCHAR            MinorFunction;
  WDF_REQUEST_TYPE Type;
  union {
    struct {
      PIO_SECURITY_CONTEXT     SecurityContext;
      ULONG                    Options;
      USHORT POINTER_ALIGNMENT FileAttributes;
      USHORT                   ShareAccess;
      ULONG POINTER_ALIGNMENT  EaLength;
    } Create;
    struct {
      size_t                  Length;
      ULONG POINTER_ALIGNMENT Key;
      LONGLONG                DeviceOffset;
    } Read;
    struct {
      size_t                  Length;
      ULONG POINTER_ALIGNMENT Key;
      LONGLONG                DeviceOffset;
    } Write;
    struct {
      size_t                   OutputBufferLength;
      size_t POINTER_ALIGNMENT InputBufferLength;
      ULONG POINTER_ALIGNMENT  IoControlCode;
      PVOID                    Type3InputBuffer;
    } DeviceIoControl;
    struct {
      PVOID                   Arg1;
      PVOID                   Arg2;
      ULONG POINTER_ALIGNMENT IoControlCode;
      PVOID                   Arg4;
    } Others;
  } Parameters;
} WDF_REQUEST_PARAMETERS, *PWDF_REQUEST_PARAMETERS;