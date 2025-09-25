PGET_NEXT_ORDERED_SERVICE PgetNextOrderedService;

DWORD PgetNextOrderedService(
  [in]      DWORD OrderingMethod,
  [in]      DWORD ExclusionFlags,
  [in, out] PIPX_SERVICE Service
)
{...}