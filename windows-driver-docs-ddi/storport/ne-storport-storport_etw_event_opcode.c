typedef enum _STORPORT_ETW_EVENT_OPCODE {
  StorportEtwEventOpcodeInfo = 0,
  StorportEtwEventOpcodeStart = 1,
  StorportEtwEventOpcodeStop = 2,
  StorportEtwEventOpcodeDC_Start = 3,
  StorportEtwEventOpcodeDC_Stop = 4,
  StorportEtwEventOpcodeExtension = 5,
  StorportEtwEventOpcodeReply = 6,
  StorportEtwEventOpcodeResume = 7,
  StorportEtwEventOpcodeSuspend = 8,
  StorportEtwEventOpcodeSend = 9,
  StorportEtwEventOpcodeReceive = 240
} STORPORT_ETW_EVENT_OPCODE, *PSTORPORT_ETW_EVENT_OPCODE;