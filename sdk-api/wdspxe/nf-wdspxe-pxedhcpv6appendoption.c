DWORD PXEAPI PxeDhcpv6AppendOption(
  [in, out] PVOID  pReply,
  [in]      ULONG  cbReply,
  [in, out] PULONG pcbReplyUsed,
  [in]      WORD   wOptionType,
  [in]      WORD   cbOption,
  [in]      PVOID  pOption
);