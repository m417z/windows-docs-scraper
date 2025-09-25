typedef union {
  NVME_CDW12_DIRECTIVE_SEND_IDENTIFY_ENABLE_DIRECTIVE EnableDirective;
  ULONG                                               AsUlong;
} NVME_CDW12_DIRECTIVE_SEND;