typedef struct _MIDL_STUB_DESC {
  void                                 *RpcInterfaceInformation;
  void * )(size_t)                                 *(pfnAllocate;
  void()(void *)                                * pfnFree;
  union {
    handle_t              *pAutoHandle;
    handle_t              *pPrimitiveHandle;
    PGENERIC_BINDING_INFO pGenericBindingInfo;
  } IMPLICIT_HANDLE_INFO;
  const NDR_RUNDOWN                    *apfnNdrRundownRoutines;
  const GENERIC_BINDING_ROUTINE_PAIR   *aGenericBindingRoutinePairs;
  const EXPR_EVAL                      *apfnExprEval;
  const XMIT_ROUTINE_QUINTUPLE         *aXmitQuintuple;
  const unsigned char                  *pFormatTypes;
  int                                  fCheckBounds;
  unsigned long                        Version;
  MALLOC_FREE_STRUCT                   *pMallocFreeStruct;
  long                                 MIDLVersion;
  const COMM_FAULT_OFFSETS             *CommFaultOffsets;
  const USER_MARSHAL_ROUTINE_QUADRUPLE *aUserMarshalQuadruple;
  const NDR_NOTIFY_ROUTINE             *NotifyRoutineTable;
  ULONG_PTR                            mFlags;
  const NDR_CS_ROUTINES                *CsRoutineTables;
  void                                 *ProxyServerInfo;
  const NDR_EXPR_DESC                  *pExprInfo;
} MIDL_STUB_DESC;