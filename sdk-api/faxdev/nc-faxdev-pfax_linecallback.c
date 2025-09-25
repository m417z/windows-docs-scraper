PFAX_LINECALLBACK PfaxLinecallback;

void PfaxLinecallback(
  [in] HANDLE FaxHandle,
  [in] DWORD hDevice,
  [in] DWORD dwMessage,
       DWORD_PTR dwInstance,
  [in] DWORD_PTR dwParam1,
  [in] DWORD_PTR dwParam2,
  [in] DWORD_PTR dwParam3
)
{...}