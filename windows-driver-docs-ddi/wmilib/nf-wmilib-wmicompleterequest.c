NTSTATUS WmiCompleteRequest(
  [in]      PDEVICE_OBJECT DeviceObject,
  [in, out] PIRP           Irp,
  [in]      NTSTATUS       Status,
  [in]      ULONG          BufferUsed,
  [in]      CCHAR          PriorityBoost
);