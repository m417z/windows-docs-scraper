typedef struct _ACTION_HEADER {
  ULONG  transport_id;
  USHORT action_code;
  USHORT reserved;
} ACTION_HEADER, *PACTION_HEADER;