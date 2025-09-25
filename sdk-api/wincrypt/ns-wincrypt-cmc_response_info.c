typedef struct _CMC_RESPONSE_INFO {
  DWORD                    cTaggedAttribute;
  PCMC_TAGGED_ATTRIBUTE    rgTaggedAttribute;
  DWORD                    cTaggedContentInfo;
  PCMC_TAGGED_CONTENT_INFO rgTaggedContentInfo;
  DWORD                    cTaggedOtherMsg;
  PCMC_TAGGED_OTHER_MSG    rgTaggedOtherMsg;
} CMC_RESPONSE_INFO, *PCMC_RESPONSE_INFO;