typedef struct _CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO {
  DWORD          dwSize;
  DWORD          cCertStore;
  HCERTSTORE     *rghCertStore;
  PFNCFILTERPROC pFilterCallback;
  void           *pvCallbackData;
} CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO, *PCRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO;