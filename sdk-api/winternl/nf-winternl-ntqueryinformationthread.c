__kernel_entry NTSTATUS NtQueryInformationThread(
  [in]            HANDLE          ThreadHandle,
  [in]            THREADINFOCLASS ThreadInformationClass,
  [in, out]       PVOID           ThreadInformation,
  [in]            ULONG           ThreadInformationLength,
  [out, optional] PULONG          ReturnLength
);