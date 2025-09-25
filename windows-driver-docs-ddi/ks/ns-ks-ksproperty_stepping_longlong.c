typedef struct {
#if ...
  ULONGLONG                  SteppingDelta;
#else
  DWORDLONG                  SteppingDelta;
#endif
  KSPROPERTY_BOUNDS_LONGLONG Bounds;
} KSPROPERTY_STEPPING_LONGLONG, *PKSPROPERTY_STEPPING_LONGLONG;