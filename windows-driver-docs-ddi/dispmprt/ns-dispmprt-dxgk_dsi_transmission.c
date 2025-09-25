typedef struct _DXGK_DSI_TRANSMISSION {
  UINT            TotalBufferSize;
  BYTE            PacketCount;
  BYTE            FailedPacket;
  struct {
    WORD TransmissionMode : 2;
    WORD ReportMipiErrors : 1;
    WORD ClearMipiErrors : 1;
    WORD SecondaryPort : 1;
    WORD ManufacturingMode : 1;
    WORD Reserved : 10;
  };
  WORD            ReadWordCount;
  WORD            FinalCommandExtraPayload;
  WORD            MipiErrors;
  WORD            HostErrors;
  DXGK_DSI_PACKET Packets[1];
} DXGK_DSI_TRANSMISSION, *PDXGK_DSI_TRANSMISSION;