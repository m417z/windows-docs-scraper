typedef union _MESSAGE {
  UPDATE_COMPLETE_MESSAGE UpdateCompleteMessage;
  DWORD                   InterfaceIndex;
} MESSAGE, *PMESSAGE;