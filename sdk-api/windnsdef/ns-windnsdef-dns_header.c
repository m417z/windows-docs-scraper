typedef struct _DNS_HEADER {
  WORD Xid;
  WORD Flags;
  BYTE RecursionDesired : 1;
  BYTE Truncation : 1;
  BYTE Authoritative : 1;
  BYTE Opcode : 4;
  BYTE IsResponse : 1;
  BYTE ResponseCode : 4;
  BYTE CheckingDisabled : 1;
  BYTE AuthenticatedData : 1;
  BYTE Reserved : 1;
  BYTE RecursionAvailable : 1;
  WORD QuestionCount;
  WORD AnswerCount;
  WORD NameServerCount;
  WORD AdditionalCount;
} DNS_HEADER, *PDNS_HEADER;