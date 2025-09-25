LSA_COPY_FROM_CLIENT_BUFFER LsaCopyFromClientBuffer;

NTSTATUS LsaCopyFromClientBuffer(
  [in] PLSA_CLIENT_REQUEST ClientRequest,
  [in] ULONG Length,
  [in] PVOID BufferToCopy,
  [in] PVOID ClientBaseAddress
)
{...}