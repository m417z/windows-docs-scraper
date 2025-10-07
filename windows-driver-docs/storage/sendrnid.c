void SendRNID(
   [in, HBAType("HBA_WWN")] uint8                                                          wwn[8],
   [in, HBAType("HBA_WWNTYPE"), Values{"NODE_WWN", "PORT_WWN"}, ValueMap{"0", "1"}] uint32 wwntype,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS                                                 HBAStatus,
   [out] uint32                                                                            ResponseBufferCount,
   [out, WmiSizeIs("ResponseBufferCount")] uint8                                           ResponseBuffer[]
);