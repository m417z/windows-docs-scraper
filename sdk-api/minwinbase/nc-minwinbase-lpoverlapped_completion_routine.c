LPOVERLAPPED_COMPLETION_ROUTINE LpoverlappedCompletionRoutine;

VOID LpoverlappedCompletionRoutine(
  [in]      DWORD dwErrorCode,
  [in]      DWORD dwNumberOfBytesTransfered,
  [in, out] LPOVERLAPPED lpOverlapped
)
{...}