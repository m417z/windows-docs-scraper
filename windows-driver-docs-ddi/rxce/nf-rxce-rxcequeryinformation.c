NTSTATUS RxCeQueryInformation(
  [in]  IN PRXCE_VC                          pVc,
  [in]  IN RXCE_CONNECTION_INFORMATION_CLASS InformationClass,
  [out] OUT PVOID                            pInformation,
  [in]  IN ULONG                             Length
);