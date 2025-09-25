typedef struct _WHEA_ERROR_RECORD_HEADER {
  ULONG                              Signature;
  WHEA_REVISION                      Revision;
  ULONG                              SignatureEnd;
  USHORT                             SectionCount;
  WHEA_ERROR_SEVERITY                Severity;
  WHEA_ERROR_RECORD_HEADER_VALIDBITS ValidBits;
  ULONG                              Length;
  WHEA_TIMESTAMP                     Timestamp;
  GUID                               PlatformId;
  GUID                               PartitionId;
  GUID                               CreatorId;
  GUID                               NotifyType;
  ULONGLONG                          RecordId;
  WHEA_ERROR_RECORD_HEADER_FLAGS     Flags;
  WHEA_PERSISTENCE_INFO              PersistenceInfo;
  union {
    struct {
      ULONG OsBuildNumber;
      UCHAR Reserved2[8];
    };
    UCHAR Reserved[12];
  };
} WHEA_ERROR_RECORD_HEADER, *PWHEA_ERROR_RECORD_HEADER;