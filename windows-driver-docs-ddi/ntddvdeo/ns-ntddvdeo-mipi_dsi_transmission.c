typedef struct _MIPI_DSI_TRANSMISSION {
  ULONG           TotalBufferSize;
  UCHAR           PacketCount;
  UCHAR           FailedPacket;
  struct {
    USHORT TransmissionMode : 2;
    USHORT ReportMipiErrors : 1;
    USHORT ClearMipiErrors : 1;
    USHORT SecondaryPort : 1;
    USHORT ManufacturingMode : 1;
    USHORT Reserved : 10;
  };
  USHORT          ReadWordCount;
  USHORT          FinalCommandExtraPayload;
  USHORT          MipiErrors;
  USHORT          HostErrors;
  MIPI_DSI_PACKET Packets[1];
} MIPI_DSI_TRANSMISSION;