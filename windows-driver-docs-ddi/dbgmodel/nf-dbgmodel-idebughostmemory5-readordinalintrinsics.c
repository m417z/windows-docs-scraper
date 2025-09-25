HRESULT ReadOrdinalIntrinsics(
  IDebugHostContext *context,
  Location          location,
  ULONG64           ordinalSize,
  bool              ordinalIsSigned,
  ULONG64           count,
  VARIANT           *vals,
  ULONG64           *intrinsicsRead
);