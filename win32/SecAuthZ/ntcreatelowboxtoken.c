NTSTATUS NTAPI NtCreateLowBoxToken(
  _Out_ PHANDLE             TokenHandle,
  _In_  HANDLE              ExistingTokenHandle,
  _In_  ACCESS_MASK         DesiredAccess,
  _in_  POBJECT_ATTRIBUTES  ObjectAttributes,
  _in_  PSID                PackageSid,
  _in_  ULONG               CapabilityCount,
  _in_  PSID_AND_ATTRIBUTES Capabilities,
  _in_  ULONG               HandleCount,
  _in_  HANDLE*             Handles
);