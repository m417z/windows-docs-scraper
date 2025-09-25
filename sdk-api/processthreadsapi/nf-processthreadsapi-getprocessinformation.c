BOOL GetProcessInformation(
  [in] HANDLE                    hProcess,
  [in] PROCESS_INFORMATION_CLASS ProcessInformationClass,
       LPVOID                    ProcessInformation,
  [in] DWORD                     ProcessInformationSize
);