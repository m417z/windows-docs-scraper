typedef struct _tag_FW_DYNAMIC_KEYWORD_ADDRESS_DATA0 {
  struct _tag_FW_DYNAMIC_KEYWORD_ADDRESS0      dynamicKeywordAddress;
  struct _tag_FW_DYNAMIC_KEYWORD_ADDRESS_DATA0 *next;
  WORD                                         schemaVersion;
  FW_DYNAMIC_KEYWORD_ORIGIN_TYPE               originType;
} FW_DYNAMIC_KEYWORD_ADDRESS_DATA0, *PFW_DYNAMIC_KEYWORD_ADDRESS_DATA0;