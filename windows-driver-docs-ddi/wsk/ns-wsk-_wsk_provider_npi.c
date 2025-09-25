typedef struct _WSK_PROVIDER_NPI {
  PWSK_CLIENT                 Client;
  const WSK_PROVIDER_DISPATCH *Dispatch;
} WSK_PROVIDER_NPI, *PWSK_PROVIDER_NPI;