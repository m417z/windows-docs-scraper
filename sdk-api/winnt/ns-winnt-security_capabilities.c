typedef struct _SECURITY_CAPABILITIES {
#if ...
  PISID               AppContainerSid;
#if ...
  PSID_AND_ATTRIBUTES Capabilities;
#else
  PSID                AppContainerSid;
#endif
#else
  PSID_AND_ATTRIBUTES Capabilities;
#endif
  DWORD               CapabilityCount;
  DWORD               Reserved;
} SECURITY_CAPABILITIES, *PSECURITY_CAPABILITIES, *LPSECURITY_CAPABILITIES;