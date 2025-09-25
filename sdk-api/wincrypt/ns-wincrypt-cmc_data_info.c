typedef struct _CMC_DATA_INFO {
  DWORD                    cTaggedAttribute;
  PCMC_TAGGED_ATTRIBUTE    rgTaggedAttribute;
  DWORD                    cTaggedRequest;
  PCMC_TAGGED_REQUEST      rgTaggedRequest;
  DWORD                    cTaggedContentInfo;
  PCMC_TAGGED_CONTENT_INFO rgTaggedContentInfo;
  DWORD                    cTaggedOtherMsg;
  PCMC_TAGGED_OTHER_MSG    rgTaggedOtherMsg;
} CMC_DATA_INFO, *PCMC_DATA_INFO;