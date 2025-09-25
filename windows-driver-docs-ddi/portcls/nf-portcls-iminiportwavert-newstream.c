NTSTATUS NewStream(
  [out] PMINIPORTWAVERTSTREAM *Stream,
  [in]  PPORTWAVERTSTREAM     PortStream,
  [in]  ULONG                 Pin,
  [in]  BOOLEAN               Capture,
  [in]  PKSDATAFORMAT         DataFormat
);