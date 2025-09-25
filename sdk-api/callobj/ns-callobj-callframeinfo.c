typedef struct __MIDL_ICallFrame_0001 {
  ULONG iMethod;
  BOOL  fHasInValues;
  BOOL  fHasInOutValues;
  BOOL  fHasOutValues;
  BOOL  fDerivesFromIDispatch;
  LONG  cInInterfacesMax;
  LONG  cInOutInterfacesMax;
  LONG  cOutInterfacesMax;
  LONG  cTopLevelInInterfaces;
  IID   iid;
  ULONG cMethod;
  ULONG cParams;
} CALLFRAMEINFO;