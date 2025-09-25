PSHED_PI_RETRIEVE_ERROR_INFO PshedPiRetrieveErrorInfo;

NTSTATUS PshedPiRetrieveErrorInfo(
  [in, out, optional] PVOID PluginContext,
  [in]                PWHEA_ERROR_SOURCE_DESCRIPTOR ErrorSource,
  [in]                ULONGLONG BufferLength,
  [in, out]           PWHEA_ERROR_PACKET Packet
)
{...}