typedef struct _EFFPERM_RESULT_LIST {
  BOOLEAN          fEvaluated;
  ULONG            cObjectTypeListLength;
  OBJECT_TYPE_LIST *pObjectTypeList;
  ACCESS_MASK      *pGrantedAccessList;
} EFFPERM_RESULT_LIST, *PEFFPERM_RESULT_LIST;