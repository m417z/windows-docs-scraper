typedef struct _IPSEC_KEY_MANAGER_CALLBACKS0 {
  GUID                                   reserved;
  UINT32                                 flags;
  IPSEC_KEY_MANAGER_KEY_DICTATION_CHECK0 keyDictationCheck;
  IPSEC_KEY_MANAGER_DICTATE_KEY0         keyDictation;
  IPSEC_KEY_MANAGER_NOTIFY_KEY0          keyNotify;
} IPSEC_KEY_MANAGER_CALLBACKS0;