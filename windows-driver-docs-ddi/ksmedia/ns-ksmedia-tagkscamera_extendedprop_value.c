typedef struct tagKSCAMERA_EXTENDEDPROP_VALUE {
  union {
    double         dbl;
    ULONGLONG      ull;
    ULONG          ul;
    ULARGE_INTEGER ratio;
    LONG           l;
    LONGLONG       ll;
  } Value;
} KSCAMERA_EXTENDEDPROP_VALUE, *PKSCAMERA_EXTENDEDPROP_VALUE;