RPC_STATUS RpcNsProfileEltInqBeginW(
  unsigned long ProfileNameSyntax,
  RPC_WSTR      ProfileName,
  unsigned long InquiryType,
  RPC_IF_ID     *IfId,
  unsigned long VersOption,
  unsigned long MemberNameSyntax,
  RPC_WSTR      MemberName,
  RPC_NS_HANDLE *InquiryContext
);