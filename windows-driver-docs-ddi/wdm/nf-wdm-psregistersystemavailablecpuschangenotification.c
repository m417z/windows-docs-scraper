NTSTATUS PsRegisterSystemAvailableCpusChangeNotification(
  [in]           PS_AVAILABLE_CPUS_CHANGE_CALLBACK     *Callback,
  [in, optional] PVOID                                 Context,
  [in, optional] PULONG64                              ObservedSequenceNumber,
  [out]          PS_AVAILABLE_CPUS_CHANGE_REGISTRATION *RegistrationHandle
);