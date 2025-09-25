typedef struct _AVC_COMMAND_IRB {
  AVC_IRB       Common;
  UCHAR         SubunitAddrFlag : 1;
  UCHAR         AlternateOpcodesFlag : 1;
  UCHAR         TimeoutFlag : 1;
  UCHAR         RetryFlag : 1;
  union {
    UCHAR CommandType;
    UCHAR ResponseCode;
  };
  PUCHAR        SubunitAddr;
  PUCHAR        AlternateOpcodes;
  LARGE_INTEGER Timeout;
  UCHAR         Retries;
  UCHAR         Opcode;
  ULONG         OperandLength;
  UCHAR         Operands[MAX_AVC_OPERAND_BYTES];
  NODE_ADDRESS  NodeAddress;
  ULONG         Generation;
} AVC_COMMAND_IRB, *PAVC_COMMAND_IRB;