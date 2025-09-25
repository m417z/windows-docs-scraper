typedef struct tagDEC {
  USHORT wReserved;
  union {
    struct {
      BYTE scale;
      BYTE sign;
    } DUMMYSTRUCTNAME;
    USHORT signscale;
  } DUMMYUNIONNAME;
  ULONG  Hi32;
  union {
    struct {
      ULONG Lo32;
      ULONG Mid32;
    } DUMMYSTRUCTNAME2;
    ULONGLONG Lo64;
  } DUMMYUNIONNAME2;
} DECIMAL;