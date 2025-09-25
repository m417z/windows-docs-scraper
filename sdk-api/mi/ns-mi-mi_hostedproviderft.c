typedef struct _MI_HostedProviderFT {
  MI_Result()(MI_HostedProvider *hostedProvider) * Close;
  MI_Result((MI_HostedProvider *hostedProvider,MI_Application *application) * )GetApplication;
} MI_HostedProviderFT;