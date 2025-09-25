typedef struct phonemessage_tag {
  DWORD     hDevice;
  DWORD     dwMessageID;
  DWORD_PTR dwCallbackInstance;
  DWORD_PTR dwParam1;
  DWORD_PTR dwParam2;
  DWORD_PTR dwParam3;
} PHONEMESSAGE, *LPPHONEMESSAGE;