LSA_COPY_TO_CLIENT_BUFFER LsaCopyToClientBuffer;

NTSTATUS LsaCopyToClientBuffer(
  [in] PLSA_CLIENT_REQUEST ClientRequest,
  [in] ULONG Length,
  [in] PVOID ClientBaseAddress,
  [in] PVOID BufferToCopy
)
{...}