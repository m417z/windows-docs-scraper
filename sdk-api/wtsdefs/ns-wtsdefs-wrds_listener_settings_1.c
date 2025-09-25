typedef struct _WRDS_LISTENER_SETTINGS_1 {
  ULONG MaxProtocolListenerConnectionCount;
#if ...
  ULONG SecurityDescriptorSize;
#if ...
  PBYTE pSecurityDescriptor;
#else
  ULONG SecurityDescriptorSize;
#endif
#else
  PBYTE pSecurityDescriptor;
#endif
} WRDS_LISTENER_SETTINGS_1, *PWRDS_LISTENER_SETTINGS_1;