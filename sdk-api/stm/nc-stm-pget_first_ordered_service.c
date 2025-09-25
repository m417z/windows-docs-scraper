PGET_FIRST_ORDERED_SERVICE PgetFirstOrderedService;

DWORD PgetFirstOrderedService(
  [in]      DWORD OrderingMethod,
  [in]      DWORD ExclusionFlags,
  [in, out] PIPX_SERVICE Service
)
{...}