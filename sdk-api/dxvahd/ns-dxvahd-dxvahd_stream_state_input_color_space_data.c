typedef struct _DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA {
  union {
    struct {
      UINT Type : 1;
      UINT RGB_Range : 1;
      UINT YCbCr_Matrix : 1;
      UINT YCbCr_xvYCC : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA;