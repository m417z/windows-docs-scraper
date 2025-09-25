typedef struct _tagSL_AD_ACTIVATION_INFO {
  SL_ACTIVATION_INFO_HEADER header;
  PCWSTR                    pwszProductKey;
  PCWSTR                    pwszActivationObjectName;
} SL_AD_ACTIVATION_INFO;