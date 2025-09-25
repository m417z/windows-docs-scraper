PADD_INTERFACE PaddInterface;

DWORD PaddInterface(
  [in] LPWSTR InterfaceName,
  [in] ULONG InterfaceIndex,
  [in] NET_INTERFACE_TYPE InterfaceType,
  [in] DWORD MediaType,
  [in] WORD AccessType,
  [in] WORD ConnectionType,
  [in] PVOID InterfaceInfo,
  [in] ULONG StructureVersion,
  [in] ULONG StructureSize,
  [in] ULONG StructureCount
)
{...}