typedef struct tcp_request_query_information_ex_xp {
  TDIObjectID ID;
  ULONG_PTR   Context[CONTEXT_SIZE / sizeof(ULONG_PTR)];
} TCP_REQUEST_QUERY_INFORMATION_EX_XP, *PTCP_REQUEST_QUERY_INFORMATION_EX_XP;