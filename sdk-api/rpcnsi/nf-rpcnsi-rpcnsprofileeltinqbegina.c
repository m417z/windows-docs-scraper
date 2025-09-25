RPC_STATUS RpcNsProfileEltInqBeginA(
  unsigned long ProfileNameSyntax,
  RPC_CSTR      ProfileName,
  unsigned long InquiryType,
  RPC_IF_ID     *IfId,
  unsigned long VersOption,
  unsigned long MemberNameSyntax,
  RPC_CSTR      MemberName,
  RPC_NS_HANDLE *InquiryContext
);