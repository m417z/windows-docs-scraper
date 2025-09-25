NTSTATUS GetRotationMatrixFromAcpi(
  WDFDEVICE Device,
  PSZ       MethodName,
  UCHAR     MethodNameLength,
  PVEC3D    RotationMatrix,
  ULONG     RotationMatrixEntries
);