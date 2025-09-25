typedef struct _SRBEX_DATA_NVME_COMMAND {
  SRBEXDATATYPE Type;
  ULONG         Length;
  union {
    PVOID     ControllerHandle;
    ULONGLONG Reserved0;
  };
  union {
    struct {
      ULONG     CommandDWORD0;
      ULONG     CommandNSID;
      ULONG     Reserved1[2];
      ULONGLONG CommandMPTR;
      union {
        struct {
          ULONGLONG CommandPRP1;
          ULONGLONG CommandPRP2;
        };
        ULONGLONG CommandSGL1[2];
      };
      ULONG     CommandCDW10;
      ULONG     CommandCDW11;
      ULONG     CommandCDW12;
      ULONG     CommandCDW13;
      ULONG     CommandCDW14;
      ULONG     CommandCDW15;
    };
    struct {
      UCHAR  OPC;
      UCHAR  PSDT;
      USHORT CID;
      UCHAR  FCTYPE;
      UCHAR  Reserved[35];
      UCHAR  Specific[24];
    } FabricsCommand;
    struct {
      ULONG OPC : 8;
      ULONG FUSE : 2;
      ULONG Reserved : 4;
      ULONG PSDT : 2;
      ULONG CID : 16;
      UCHAR TypeSpecific[60];
    } Command;
  };
  UCHAR         CommandType;
  UCHAR         Reserved2;
  USHORT        CommandFlags;
  USHORT        ResponseFlags;
  union {
    struct {
      USHORT P : 1;
      USHORT SC : 8;
      USHORT SCT : 3;
      USHORT CRD : 2;
      USHORT M : 1;
      USHORT DNR : 1;
    } DUMMYSTRUCTNAME;
    USHORT AsUshort;
  } CommandStatus;
  ULONG         QID;
  ULONG         CommandTag;
  union {
    struct {
      ULONG CQEntryDW0;
      ULONG CQEntryDW1;
    };
    UCHAR Specific[8];
  };
  USHORT        SQHD;
  USHORT        SQID;
} SRBEX_DATA_NVME_COMMAND, *PSRBEX_DATA_NVME_COMMAND;