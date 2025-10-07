DWORD APIENTRY NtGdiDdFlip(
  _In_    HANDLE       hSurfaceCurrent,
  _In_    HANDLE       hSurfaceTarget,
  _In_    HANDLE       hSurfaceCurrentLeft,
  _In_    HANDLE       hSurfaceTargetLeft,
  _Inout_ PDD_FLIPDATA puFlipData
);