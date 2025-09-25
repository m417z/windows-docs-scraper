SECURITY_STATUS TokenBindingGenerateMessage(
  [in]  const void * [] tokenBindings,
  [in]  const DWORD []  tokenBindingsSize,
  [in]  DWORD           tokenBindingsCount,
  [out] void            **tokenBindingMessage,
  [out] DWORD           *tokenBindingMessageSize
);