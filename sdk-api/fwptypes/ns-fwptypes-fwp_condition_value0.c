typedef struct FWP_CONDITION_VALUE0_ {
  FWP_DATA_TYPE type;
  union {
    UINT8                 uint8;
    UINT16                uint16;
    UINT32                uint32;
    UINT64                *uint64;
    INT8                  int8;
    INT16                 int16;
    INT32                 int32;
    INT64                 *int64;
    float                 float32;
    double                *double64;
    FWP_BYTE_ARRAY16      *byteArray16;
    FWP_BYTE_BLOB         *byteBlob;
    SID                   *sid;
    FWP_BYTE_BLOB         *sd;
    FWP_TOKEN_INFORMATION *tokenInformation;
    FWP_BYTE_BLOB         *tokenAccessInformation;
    LPWSTR                unicodeString;
    FWP_BYTE_ARRAY6       *byteArray6;
    FWP_V4_ADDR_AND_MASK  *v4AddrMask;
    FWP_V6_ADDR_AND_MASK  *v6AddrMask;
    FWP_RANGE0            *rangeValue;
  };
} FWP_CONDITION_VALUE0;