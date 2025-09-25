typedef struct _DEBUG_VALUE {
  union {
    UCHAR   I8;
    USHORT  I16;
    ULONG   I32;
    struct {
      ULONG64 I64;
      BOOL    Nat;
    };
    float   F32;
    double  F64;
    UCHAR   F80Bytes[10];
    UCHAR   F82Bytes[11];
    UCHAR   F128Bytes[16];
    UCHAR   VI8[16];
    USHORT  VI16[8];
    ULONG   VI32[4];
    ULONG64 VI64[2];
    float   VF32[4];
    double  VF64[2];
    struct {
      ULONG LowPart;
      ULONG HighPart;
    } I64Parts32;
    struct {
      ULONG64 LowPart;
      LONG64  HighPart;
    } F128Parts64;
    UCHAR   RawBytes[24];
  };
  ULONG TailOfRawBytes;
  ULONG Type;
} DEBUG_VALUE, *PDEBUG_VALUE;