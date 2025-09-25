typedef struct _DKGK_GAMMA_DATA_CAP {
  DXGK_GAMMA_DATA_TYPE DataType;
  union {
    struct {
      UINT BitCountOfInteger : 6;
      UINT BitCountOfFraction : 6;
    };
    struct {
      UINT BitCountOfExponent : 6;
      UINT BitCountOfMantissa : 6;
    };
    UINT Value;
  };
  float                NumericRangeMin;
  float                NumericRangeMax;
} DKGK_GAMMA_DATA_CAP;