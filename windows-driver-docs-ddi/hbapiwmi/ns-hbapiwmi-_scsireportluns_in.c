typedef struct _ScsiReportLuns_IN {
  UCHAR Cdb[12];
  UCHAR HbaPortWWN[8];
  UCHAR DiscoveredPortWWN[8];
} ScsiReportLuns_IN, *PScsiReportLuns_IN;