typedef struct _MI_HostedProvider {
  MI_Uint64                 reserved1;
  ptrdiff_t                 reserved2;
  const MI_HostedProviderFT *ft;
} MI_HostedProvider;