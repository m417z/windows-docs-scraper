typedef struct _DXGKARG_QUERYDEPENDENTENGINEGROUP {
  [in]  UINT      NodeOrdinal;
  [in]  UINT      EngineOrdinal;
  [out] ULONGLONG DependentNodeOrdinalMask;
} DXGKARG_QUERYDEPENDENTENGINEGROUP;