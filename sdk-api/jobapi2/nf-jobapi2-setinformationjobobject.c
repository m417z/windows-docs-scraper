BOOL SetInformationJobObject(
  [in] HANDLE             hJob,
  [in] JOBOBJECTINFOCLASS JobObjectInformationClass,
  [in] LPVOID             lpJobObjectInformation,
  [in] DWORD              cbJobObjectInformationLength
);