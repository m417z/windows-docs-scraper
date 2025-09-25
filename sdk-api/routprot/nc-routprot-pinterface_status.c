PINTERFACE_STATUS PinterfaceStatus;

DWORD PinterfaceStatus(
  [in] ULONG InterfaceIndex,
  [in] BOOL InterfaceActive,
  [in] DWORD StatusType,
  [in] PVOID StatusInfo
)
{...}