BOOL GetThreadInformation(
  [in] HANDLE                   hThread,
  [in] THREAD_INFORMATION_CLASS ThreadInformationClass,
       LPVOID                   ThreadInformation,
  [in] DWORD                    ThreadInformationSize
);