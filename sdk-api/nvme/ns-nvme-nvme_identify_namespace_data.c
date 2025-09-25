typedef struct {
  ULONGLONG                    NSZE;
  ULONGLONG                    NCAP;
  ULONGLONG                    NUSE;
  struct {
    UCHAR ThinProvisioning : 1;
    UCHAR NameSpaceAtomicWriteUnit : 1;
    UCHAR DeallocatedOrUnwrittenError : 1;
    UCHAR SkipReuseUI : 1;
    UCHAR NameSpaceIoOptimization : 1;
    UCHAR Reserved : 3;
  } NSFEAT;
  UCHAR                        NLBAF;
  struct {
    UCHAR LbaFormatIndex : 4;
    UCHAR MetadataInExtendedDataLBA : 1;
    UCHAR Reserved : 3;
  } FLBAS;
  struct {
    UCHAR MetadataInExtendedDataLBA : 1;
    UCHAR MetadataInSeparateBuffer : 1;
    UCHAR Reserved : 6;
  } MC;
  struct {
    UCHAR ProtectionInfoType1 : 1;
    UCHAR ProtectionInfoType2 : 1;
    UCHAR ProtectionInfoType3 : 1;
    UCHAR InfoAtBeginningOfMetadata : 1;
    UCHAR InfoAtEndOfMetadata : 1;
    UCHAR Reserved : 3;
  } DPC;
  struct {
    UCHAR ProtectionInfoTypeEnabled : 3;
    UCHAR InfoAtBeginningOfMetadata : 1;
    UCHAR Reserved : 4;
  } DPS;
  struct {
    UCHAR SharedNameSpace : 1;
    UCHAR Reserved : 7;
  } NMIC;
  NVM_RESERVATION_CAPABILITIES RESCAP;
  struct {
    UCHAR PercentageRemained : 7;
    UCHAR Supported : 1;
  } FPI;
  struct {
    UCHAR ReadBehavior : 3;
    UCHAR WriteZeroes : 1;
    UCHAR GuardFieldWithCRC : 1;
    UCHAR Reserved : 3;
  } DLFEAT;
  USHORT                       NAWUN;
  USHORT                       NAWUPF;
  USHORT                       NACWU;
  USHORT                       NABSN;
  USHORT                       NABO;
  USHORT                       NABSPF;
  USHORT                       NOIOB;
  UCHAR                        NVMCAP[16];
  USHORT                       NPWG;
  USHORT                       NPWA;
  USHORT                       NPDG;
  USHORT                       NPDA;
  USHORT                       NOWS;
  USHORT                       MSSRL;
  ULONG                        MCL;
  UCHAR                        MSRC;
  UCHAR                        Reserved2[11];
  ULONG                        ANAGRPID;
  UCHAR                        Reserved3[3];
  struct {
    UCHAR WriteProtected : 1;
    UCHAR Reserved : 7;
  } NSATTR;
  USHORT                       NVMSETID;
  USHORT                       ENDGID;
  UCHAR                        NGUID[16];
  UCHAR                        EUI64[8];
  NVME_LBA_FORMAT              LBAF[16];
  UCHAR                        Reserved4[192];
  UCHAR                        VS[3712];
} NVME_IDENTIFY_NAMESPACE_DATA, *PNVME_IDENTIFY_NAMESPACE_DATA;