LPWSAOVERLAPPED_COMPLETION_ROUTINE LpwsaoverlappedCompletionRoutine;

void LpwsaoverlappedCompletionRoutine(
  DWORD dwError,
  DWORD cbTransferred,
  LPWSAOVERLAPPED lpOverlapped,
  DWORD dwFlags
)
{...}