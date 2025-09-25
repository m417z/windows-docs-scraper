PWAITCHAINCALLBACK Pwaitchaincallback;

VOID Pwaitchaincallback(
  HWCT WctHandle,
  DWORD_PTR Context,
  DWORD CallbackStatus,
  LPDWORD NodeCount,
  PWAITCHAIN_NODE_INFO NodeInfoArray,
  LPBOOL IsCycle
)
{...}