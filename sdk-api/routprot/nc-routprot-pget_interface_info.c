PGET_INTERFACE_INFO PgetInterfaceInfo;

DWORD PgetInterfaceInfo(
  [in]      ULONG InterfaceIndex,
  [in]      PVOID InterfaceInfo,
  [in, out] PULONG BufferSize,
  [in]      PULONG StructureVersion,
  [in]      PULONG StructureSize,
  [in]      PULONG StructureCount
)
{...}