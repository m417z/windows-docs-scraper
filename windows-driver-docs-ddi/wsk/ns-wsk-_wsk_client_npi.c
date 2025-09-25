typedef struct _WSK_CLIENT_NPI {
  PVOID                     ClientContext;
  const WSK_CLIENT_DISPATCH *Dispatch;
} WSK_CLIENT_NPI, *PWSK_CLIENT_NPI;