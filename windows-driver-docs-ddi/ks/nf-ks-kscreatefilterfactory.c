KSDDKAPI NTSTATUS KsCreateFilterFactory(
  [in]            PDEVICE_OBJECT            DeviceObject,
  [in]            const KSFILTER_DESCRIPTOR *Descriptor,
  [in, optional]  PWSTR                     RefString,
  [in, optional]  PSECURITY_DESCRIPTOR      SecurityDescriptor,
  [in]            ULONG                     CreateItemFlags,
  [in, optional]  PFNKSFILTERFACTORYPOWER   SleepCallback,
  [in, optional]  PFNKSFILTERFACTORYPOWER   WakeCallback,
  [out, optional] PKSFILTERFACTORY          *FilterFactory
);