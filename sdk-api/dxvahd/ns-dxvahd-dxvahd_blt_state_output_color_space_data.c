typedef struct _DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA {
  union {
    struct {
      UINT Usage : 1;
      UINT RGB_Range : 1;
      UINT YCbCr_Matrix : 1;
      UINT YCbCr_xvYCC : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA;