typedef struct _ACX_EVENT_CONFIG {
  ULONG                Size;
  ULONG                Flags;
  const GUID           *Set;
  ULONG                Id;
  ULONG                Type;
  PACX_EVENT_CALLBACKS Callbacks;
} ACX_EVENT_CONFIG, *PACX_EVENT_CONFIG;