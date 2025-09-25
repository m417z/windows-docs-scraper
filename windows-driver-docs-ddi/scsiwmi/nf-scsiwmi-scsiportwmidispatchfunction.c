BOOLEAN ScsiPortWmiDispatchFunction(
  [in] PSCSI_WMILIB_CONTEXT     WmiLibInfo,
  [in] UCHAR                    MinorFunction,
  [in] PVOID                    DeviceContext,
  [in] PSCSIWMI_REQUEST_CONTEXT RequestContext,
  [in] PVOID                    DataPath,
  [in] ULONG                    BufferSize,
  [in] PVOID                    Buffer
);