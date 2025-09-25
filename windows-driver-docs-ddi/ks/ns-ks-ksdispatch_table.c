typedef struct {
  PDRIVER_DISPATCH        DeviceIoControl;
  PDRIVER_DISPATCH        Read;
  PDRIVER_DISPATCH        Write;
  PDRIVER_DISPATCH        Flush;
  PDRIVER_DISPATCH        Close;
  PDRIVER_DISPATCH        QuerySecurity;
  PDRIVER_DISPATCH        SetSecurity;
  PFAST_IO_DEVICE_CONTROL FastDeviceIoControl;
  PFAST_IO_READ           FastRead;
  PFAST_IO_WRITE          FastWrite;
} KSDISPATCH_TABLE, *PKSDISPATCH_TABLE;