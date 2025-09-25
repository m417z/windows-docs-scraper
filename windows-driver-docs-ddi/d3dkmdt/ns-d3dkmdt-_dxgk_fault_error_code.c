typedef struct _DXGK_FAULT_ERROR_CODE {
  union {
    struct {
      UINT                    IsDeviceSpecificCode : 1;
      DXGK_GENERAL_ERROR_CODE GeneralErrorCode : 31;
    };
    struct {
      UINT IsDeviceSpecificCodeReservedBit : 1;
      UINT DeviceSpecificCode : 31;
    };
  };
} DXGK_FAULT_ERROR_CODE;