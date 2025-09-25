typedef struct _COLORSPACE_TRANSFORM_DATA_CAP {
  COLORSPACE_TRANSFORM_DATA_TYPE DataType;
  union {
    struct {
      ULONG BitCountOfInteger : 6;
      ULONG BitCountOfFraction : 6;
    };
    struct {
      ULONG BitCountOfExponent : 6;
      ULONG BitCountOfMantissa : 6;
    };
    ULONG Value;
  };
  float                          NumericRangeMin;
  float                          NumericRangeMax;
} COLORSPACE_TRANSFORM_DATA_CAP;