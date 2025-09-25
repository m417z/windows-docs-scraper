typedef union {
  struct {
    LONGLONG SignedMinimum;
    LONGLONG SignedMaximum;
  } _SIGNED64;
  struct {
    LONGLONG SignedMinimum;
    LONGLONG SignedMaximum;
  };
  struct {
    ULONGLONG UnsignedMinimum;
    ULONGLONG UnsignedMaximum;
  } _UNSIGNED64;
  struct {
    DWORDLONG UnsignedMinimum;
    DWORDLONG UnsignedMaximum;
  };
} KSPROPERTY_BOUNDS_LONGLONG, *PKSPROPERTY_BOUNDS_LONGLONG;