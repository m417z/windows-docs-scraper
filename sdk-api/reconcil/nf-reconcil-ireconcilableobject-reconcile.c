HRESULT Reconcile(
  IReconcileInitiator *pInitiator,
  DWORD               dwFlags,
  HWND                hwndOwner,
  HWND                hwndProgressFeedback,
  ULONG               ulcInput,
  IMoniker            **rgpmkOtherInput,
  PLONG               plOutIndex,
  IStorage            *pstgNewResidues,
  PVOID               pvReserved
);