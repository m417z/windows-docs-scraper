typedef struct IORING_CQE {
  UINT_PTR  UserData;
  HRESULT   ResultCode;
  ULONG_PTR Information;
} IORING_CQE;