BOOL QueryInformationJobObject(
  [in, optional]  HANDLE             hJob,
  [in]            JOBOBJECTINFOCLASS JobObjectInformationClass,
  [out]           LPVOID             lpJobObjectInformation,
  [in]            DWORD              cbJobObjectInformationLength,
  [out, optional] LPDWORD            lpReturnLength
);