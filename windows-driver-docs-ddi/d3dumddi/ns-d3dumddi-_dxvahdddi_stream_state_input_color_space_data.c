typedef struct _DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA {
  union {
    struct {
      UINT Type : 1;
      UINT RGB_Range : 1;
      UINT YCbCr_Matrix : 1;
      UINT YCbCr_xvYCC : 1;
      UINT Nominal_Range : 2;
      UINT Reserved : 26;
    };
    [in] UINT Value;
  };
} DXVAHDDDI_STREAM_STATE_INPUT_COLOR_SPACE_DATA;