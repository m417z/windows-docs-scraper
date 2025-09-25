typedef enum WbemFlagEnum {
  wbemFlagReturnImmediately = 0x10,
  wbemFlagReturnWhenComplete = 0,
  wbemFlagBidirectional = 0,
  wbemFlagForwardOnly = 0x20,
  wbemFlagNoErrorObject = 0x40,
  wbemFlagReturnErrorObject = 0,
  wbemFlagSendStatus = 0x80,
  wbemFlagDontSendStatus = 0,
  wbemFlagEnsureLocatable = 0x100,
  wbemFlagDirectRead = 0x200,
  wbemFlagSendOnlySelected = 0,
  wbemFlagUseAmendedQualifiers = 0x20000,
  wbemFlagGetDefault = 0,
  wbemFlagSpawnInstance = 0x1,
  wbemFlagUseCurrentTime = 0x1
} ;