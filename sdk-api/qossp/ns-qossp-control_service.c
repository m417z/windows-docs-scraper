typedef struct _CONTROL_SERVICE {
  ULONG             Length;
  SERVICETYPE       Service;
  AD_GENERAL_PARAMS Overrides;
  union {
    AD_GUARANTEED Guaranteed;
    PARAM_BUFFER  ParamBuffer[1];
  };
} CONTROL_SERVICE, *LPCONTROL_SERVICE;